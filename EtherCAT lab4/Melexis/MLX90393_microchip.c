#include <Melexis/MLX90393_microchip.h>
#include <utils.h>
#include <utils_assert.h>

void initialize(struct MLX90393 *hall_sensor) {
    hall_sensor->I2C_prefix = 0;
    hall_sensor->I2C_address = 0;

    //i2c_m_sync_get_io_descriptor(&I2C_0, &bmx_io); // not necessairy  

    // gain steps derived from data sheet section 15.1.4 tables
    hall_sensor->gain_multipliers[0] = 5.f;
    hall_sensor->gain_multipliers[1] = 4.f;
    hall_sensor->gain_multipliers[2] = 3.f;
    hall_sensor->gain_multipliers[3] = 2.5f;
    hall_sensor->gain_multipliers[4] = 2.f;
    hall_sensor->gain_multipliers[5] = 1.66666667f;
    hall_sensor->gain_multipliers[6] = 1.33333333f;
    hall_sensor->gain_multipliers[7] = 1.f;

    // for hallconf = 0
    hall_sensor->base_xy_sens_hc0 = 0.196f;
    hall_sensor->base_z_sens_hc0 = 0.316f;
    // for hallconf = 0xc
    hall_sensor->base_xy_sens_hc0xc = 0.150f;
    hall_sensor->base_z_sens_hc0xc = 0.242f;

    cache_invalidate(hall_sensor);
 
}

uint8_t select_prefix(struct MLX90393 *hall_sensor, int order_code_last_digit)
{
    switch(order_code_last_digit){
        case 1: 
          hall_sensor->I2C_prefix = I2C_PREFIX_011 << 2;
          break;//I2C_PREFIX_011 << 3;
        case 2: 
          hall_sensor->I2C_prefix = I2C_PREFIX_012 << 2;
          break;//I2C_PREFIX_012 << 2;
        case 3: 
          hall_sensor->I2C_prefix = I2C_PREFIX_013 << 2;
          break;//I2C_PREFIX_013 << 1;
        case 4: 
          hall_sensor->I2C_prefix = I2C_PREFIX_014 << 2;
          break;//I2C_PREFIX_014 << 1;
    }
    return hall_sensor->I2C_prefix;
}

uint8_t begin(struct MLX90393 *hall_sensor, int order_code_last_digit, uint8_t A1, uint8_t A0, bool DRDY, struct io_descriptor *io) //int DRDY_pin, TwoWire &wirePort
{
  select_prefix(hall_sensor, order_code_last_digit);
  hall_sensor->I2C_address = hall_sensor->I2C_prefix | (A1?2:0) | (A0?1:0);
  hall_sensor->DRDY_pin = DRDY;
  
  /*
   implement your implementation of interrupt pin here 
  */

  //tbd
  exit_command(hall_sensor, io);
  uint8_t status1 = checkStatus(reset(hall_sensor, io));
  uint8_t status2 = setGainSel(hall_sensor, 2, io); //7
  uint8_t status3 = setResolution(hall_sensor, 0, 0, 0, io); //0,0,0
  uint8_t status4 = setOverSampling(hall_sensor, 1, io); //3
  uint8_t status5 = setDigitalFiltering(hall_sensor, 2, io); //7
  uint8_t status6 = setTemperatureCompensation(hall_sensor, 0, io);//0

  return status1 | status2 | status3 | status4 | status5 | status6;
}

//sensor communication

uint8_t sendCommand(struct MLX90393 *hall_sensor, uint8_t cmd, struct io_descriptor *io)
{
  
  i2c_m_sync_set_slaveaddr(&I2C_0, hall_sensor->I2C_address, I2C_M_SEVEN);
  int32_t ret;

  uint8_t buffer_answer[1];
  ret = i2c_m_sync_cmd_write_easy(io, cmd, (uint8_t *)buffer_answer, (uint16_t) 1);
  
  if (ret < 1) {return STATUS_ERROR;}
  return buffer_answer[0];
  
}

//Buffer muss geprüft werden
uint8_t readRegister(struct MLX90393 *hall_sensor, uint8_t address, uint16_t *data, struct io_descriptor *io)
{
  i2c_m_sync_set_slaveaddr(&I2C_0, hall_sensor->I2C_address, I2C_M_SEVEN);
  
  int32_t ret;
  uint8_t cmd = CMD_READ_REGISTER;
  uint8_t reg_adress = (address & 0x3f)<<2;
  uint8_t buffer[3];

  ret = i2c_m_sync_reg_read_easy(io, cmd, reg_adress, (uint8_t *)buffer, (uint16_t) 3);
  if (ret < 1) {return STATUS_ERROR;}
  
  uint8_t status = buffer[0];
  uint8_t b_h = buffer[1];
  uint8_t b_l = buffer[2];

  *(data) = ((uint16_t) b_h <<8) | b_l;
  cache_set(hall_sensor, address, *(data));
  return status;
}

uint8_t writeRegister(struct MLX90393 *hall_sensor, uint8_t address, uint16_t data, struct io_descriptor *io)
{
  cache_invalidate_address(hall_sensor, address);

  i2c_m_sync_set_slaveaddr(&I2C_0, hall_sensor->I2C_address, I2C_M_SEVEN);
  
  int32_t ret;
  uint8_t cmd = CMD_WRITE_REGISTER;
  uint8_t reg_adress = (address & 0x3f)<<2;
  uint8_t buffer_answer[1];
    
  ret = i2c_m_sync_reg_write_easy(io, cmd, data, reg_adress, (uint8_t *)buffer_answer);
  
  if (ret < 1) {return STATUS_ERROR;}
  
  const uint8_t status = buffer_answer[0];
  if (isOK(status)) {
    cache_set(hall_sensor, address, data);
  }
  return status;
}

int32_t i2c_m_sync_cmd_write_easy(struct io_descriptor *io, const uint8_t cmd, const uint8_t *const buf_answer, const uint16_t length_answer)
{
	int32_t ret;
	
	uint8_t buffer_write[1] = {cmd}; 
	ret = io_write(io, (uint8_t *)buffer_write, 1);
	if (ret != 1) {return -1;}
	
	ret = io_read(io, (uint8_t *)buf_answer,length_answer);
	if (ret != length_answer) {return -1;}
		
	return 1;
}

int32_t i2c_m_sync_reg_read_easy(struct io_descriptor *io, uint8_t cmd, uint8_t reg, const uint8_t *const buf_answer, const uint16_t length_answer)
{
	int32_t ret;
	uint8_t buffer_write[2] = {0};
	buffer_write[0] = cmd;
	buffer_write[1]	= reg;
		
	ret = io_write(io, (uint8_t *)buffer_write, 2);
	if (ret != 2) {return -1;}

	ret = io_read(io, (uint8_t *) buf_answer,length_answer);
	if (ret != length_answer) {return -1;}
	
	return 1;
}

int32_t i2c_m_sync_reg_write_easy(struct io_descriptor *io, uint8_t cmd, uint16_t data, uint8_t reg, const uint8_t *const buf_answer)
{
	int32_t ret;

	uint8_t buffer_write[4] = {0};
	buffer_write[0] = cmd;
	buffer_write[1] = (data & 0xff00) >> 8;
	buffer_write[2] = data & 0x00ff;
	buffer_write[3] = reg;
	
	ret = io_write(io, (uint8_t *)buffer_write, 4);
	if (ret != 4) {return -1;}
		
	ret = io_read(io, (uint8_t *)buf_answer,1);
	if (ret != 1) {return -1;}
	
	return 1;
		
}


// cache functions
void cache_invalidate(struct MLX90393 *hall_sensor)
{
  hall_sensor->cache.dirty = ALL_DIRTY_MASK;
}

void cache_invalidate_address(struct MLX90393 *hall_sensor, uint8_t address)
{
  hall_sensor->cache.dirty |= ALL_DIRTY_MASK & (1<<address);
}

void cache_set(struct MLX90393 *hall_sensor, uint8_t address, uint16_t data){
  if (address < CACHESIZE){
    hall_sensor->cache.reg[address] = data;
    hall_sensor->cache.dirty &= ~(1 << address);
  }
}

uint8_t cache_fill(struct MLX90393 *hall_sensor, struct io_descriptor *io) {
  if (hall_sensor->cache.dirty != 0) {
    for (uint8_t address=0; address < CACHESIZE; ++address){
      if (hall_sensor->cache.dirty & (1 << address)){
        if (hasError(readRegister(hall_sensor, address, &(hall_sensor->cache.reg[address]), io))) {
          return STATUS_ERROR;
        }
      }
    }
  }
  return STATUS_OK;
}

//sensor commands 

uint8_t reset(struct MLX90393 *hall_sensor, struct io_descriptor *io)
{
  cache_invalidate(hall_sensor);

  uint8_t status = sendCommand(hall_sensor, CMD_RESET, io);
  //Device now resets. We must give it time to complete
  delay_ms(3);
  // POR is 1.6ms max. Software reset time limit is not specified.
  // 2ms was found to be good.

  return status;
}

uint8_t setGainSel(struct MLX90393 *hall_sensor, uint8_t gain_sel, struct io_descriptor *io)
{
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, GAIN_SEL_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, GAIN_SEL_REG, (old_val & ~GAIN_SEL_MASK) | (((uint16_t) gain_sel << GAIN_SEL_SHIFT) & GAIN_SEL_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getGainSel(struct MLX90393 *hall_sensor, uint8_t gain_sel, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, GAIN_SEL_REG, &reg_val, io);
  gain_sel = (reg_val & GAIN_SEL_MASK) >> GAIN_SEL_SHIFT;
  return checkStatus(status);
}

uint8_t setHallConf(struct MLX90393 *hall_sensor, uint8_t hallconf, struct io_descriptor *io)
{
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, HALLCONF_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, HALLCONF_REG, (old_val & ~HALLCONF_MASK) | (((uint16_t) hallconf << HALLCONF_SHIFT) & HALLCONF_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getHallConf(struct MLX90393 *hall_sensor, uint8_t hallconf, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, HALLCONF_REG, &reg_val, io);
  hallconf = (reg_val & HALLCONF_MASK) >> HALLCONF_SHIFT;
  return checkStatus(status);
}

uint8_t setResolution(struct MLX90393 *hall_sensor, uint8_t res_x, uint8_t res_y, uint8_t res_z, struct io_descriptor *io)
{
  uint16_t res_xyz = ((res_z & 0x3)<<4) | ((res_y & 0x3)<<2) | (res_x & 0x3);
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, RES_XYZ_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, RES_XYZ_REG, (old_val & ~RES_XYZ_MASK) | ((res_xyz << RES_XYZ_SHIFT) & RES_XYZ_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getResolution(struct MLX90393 *hall_sensor, uint8_t res_x, uint8_t res_y, uint8_t res_z, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, RES_XYZ_REG, &reg_val, io);
  uint8_t res_xyz = (reg_val & RES_XYZ_MASK) >> RES_XYZ_SHIFT;
  res_x = (res_xyz >> 0) & 0x3;
  res_y = (res_xyz >> 2) & 0x3;
  res_z = (res_xyz >> 4) & 0x3;
  return checkStatus(status);
}

uint8_t setOverSampling(struct MLX90393 *hall_sensor, uint8_t osr, struct io_descriptor *io)
{
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, OSR_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, OSR_REG, (old_val & ~OSR_MASK) | (((uint16_t)osr << OSR_SHIFT) & OSR_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getOverSampling(struct MLX90393 *hall_sensor, uint8_t osr, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, OSR_REG, &reg_val, io);
  osr = (reg_val & OSR_MASK) >> OSR_SHIFT;
  return checkStatus(status);
}

uint8_t setDigitalFiltering(struct MLX90393 *hall_sensor, uint8_t dig_flt, struct io_descriptor *io)
{
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, DIG_FLT_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, DIG_FLT_REG, (old_val & ~DIG_FLT_MASK) | (((uint16_t) dig_flt << DIG_FLT_SHIFT) & DIG_FLT_MASK),io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getDigitalFiltering(struct MLX90393 *hall_sensor, uint8_t dig_flt, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, DIG_FLT_REG, &reg_val, io);
  dig_flt = (reg_val & DIG_FLT_MASK) >> DIG_FLT_SHIFT;
  return checkStatus(status);
}

uint8_t setTemperatureCompensation(struct MLX90393 *hall_sensor, uint8_t enabled, struct io_descriptor *io)
{
  uint8_t tcmp_en = enabled?1:0;
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, TCMP_EN_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, TCMP_EN_REG, (old_val & ~TCMP_EN_MASK) | (((uint16_t) tcmp_en << TCMP_EN_SHIFT) & TCMP_EN_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getTemperatureCompensation(struct MLX90393 *hall_sensor, uint8_t enabled, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, TCMP_EN_REG, &reg_val, io);
  enabled = (reg_val & TCMP_EN_MASK) >> TCMP_EN_SHIFT;
  return checkStatus(status);
}

uint8_t setTemperatureOverSampling(struct MLX90393 *hall_sensor, uint8_t osr2, struct io_descriptor *io)
{
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, OSR2_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, OSR2_REG, (old_val & ~OSR2_MASK) | (((uint16_t) osr2 << OSR2_SHIFT) & OSR2_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getTemperatureOverSampling(struct MLX90393 *hall_sensor, uint8_t osr2, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, OSR2_REG, &reg_val, io);
  osr2 = (reg_val & OSR2_MASK) >> OSR2_SHIFT;
  return checkStatus(status);
}

uint8_t setBurstSel(struct MLX90393 *hall_sensor, uint8_t burst_sel, struct io_descriptor *io)
{
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, BURST_SEL_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, BURST_SEL_REG, (old_val & ~BURST_SEL_MASK) | (((uint16_t) burst_sel << BURST_SEL_SHIFT) & BURST_SEL_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getBurstSel(struct MLX90393 *hall_sensor, uint8_t burst_sel, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, BURST_SEL_REG, &reg_val, io);
  burst_sel = (reg_val & BURST_SEL_MASK) >> BURST_SEL_SHIFT;
  return checkStatus(status);
}

uint8_t setExtTrig(struct MLX90393 *hall_sensor, int8_t ext_trig, struct io_descriptor *io)
{
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, EXT_TRIG_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, EXT_TRIG_REG, (old_val & ~EXT_TRIG_MASK) | (((uint16_t) ext_trig << EXT_TRIG_SHIFT) & EXT_TRIG_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getExtTrig(struct MLX90393 *hall_sensor, uint8_t ext_trig, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, EXT_TRIG_REG, &reg_val, io);
  ext_trig = (reg_val & EXT_TRIG_MASK) >> EXT_TRIG_SHIFT;
  return checkStatus(status);

}

uint8_t setTrigIntSel(struct MLX90393 *hall_sensor, uint8_t trig_int_sel, struct io_descriptor *io)
{
  uint16_t old_val = 0;
  uint8_t status1 = readRegister(hall_sensor, TRIG_INT_SEL_REG, &old_val, io);
  uint8_t status2 = writeRegister(hall_sensor, TRIG_INT_SEL_REG, (old_val & ~TRIG_INT_SEL_MASK) | (((uint16_t)trig_int_sel << TRIG_INT_SEL_SHIFT) & TRIG_INT_SEL_MASK), io);
  return checkStatus(status1) | checkStatus(status2);
}

uint8_t getTrigIntSel(struct MLX90393 *hall_sensor, uint8_t trig_int_sel, struct io_descriptor *io)
{
  uint16_t reg_val = 0;
  uint8_t status = readRegister(hall_sensor, TRIG_INT_SEL_REG, &reg_val, io);
  trig_int_sel = (reg_val & TRIG_INT_SEL_MASK) >> TRIG_INT_SEL_SHIFT;
  return checkStatus(status);
}

uint8_t setOffsets(struct MLX90393 *hall_sensor, uint16_t x, uint16_t y, uint16_t z, struct io_descriptor *io)
{
  uint8_t status1 = writeRegister(hall_sensor, X_OFFSET_REG, x, io);
  uint8_t status2 = writeRegister(hall_sensor, Y_OFFSET_REG, y, io);
  uint8_t status3 = writeRegister(hall_sensor, Z_OFFSET_REG, z, io);
  return checkStatus(status1) | checkStatus(status2) | checkStatus(status3);
}

uint8_t setWOXYThreshold(struct MLX90393 *hall_sensor, uint16_t woxy_thresh, struct io_descriptor *io)
{
  uint8_t status = writeRegister(hall_sensor, WOXY_THRESHOLD_REG, woxy_thresh, io);
  return checkStatus(status);
}

uint8_t setWOZThreshold(struct MLX90393 *hall_sensor, uint16_t woz_thresh, struct io_descriptor *io)
{
  uint8_t status = writeRegister(hall_sensor, WOZ_THRESHOLD_REG, woz_thresh, io);
  return checkStatus(status);
}

uint8_t setWOTThreshold(struct MLX90393 *hall_sensor, uint16_t wot_thresh, struct io_descriptor *io)
{
  uint8_t status = writeRegister(hall_sensor, WOT_THRESHOLD_REG, wot_thresh, io);
  return checkStatus(status);
}

uint8_t nop(struct MLX90393 *hall_sensor, struct io_descriptor *io)
{
  return sendCommand(hall_sensor, CMD_NOP, io);
}

uint8_t exit_command(struct MLX90393 *hall_sensor, struct io_descriptor *io)
{
  return sendCommand(hall_sensor, CMD_EXIT, io);
  delay_ms(2);
}

uint8_t startBurst(struct MLX90393 *hall_sensor, uint8_t zyxt_flags, struct io_descriptor *io)
{
  cache_fill(hall_sensor, io);
  uint8_t cmd = CMD_START_BURST | (zyxt_flags & 0xf);
  return sendCommand(hall_sensor, cmd, io);
}

uint8_t startWakeOnChange(struct MLX90393 *hall_sensor, uint8_t zyxt_flags, struct io_descriptor *io)
{
  cache_fill(hall_sensor, io);
  uint8_t cmd = CMD_WAKE_ON_CHANGE | (zyxt_flags & 0xf);
  return sendCommand(hall_sensor, cmd, io);
}

uint8_t startMeasurement(struct MLX90393 *hall_sensor, uint8_t zyxt_flags, struct io_descriptor *io)
{
  cache_fill(hall_sensor, io);
  uint8_t cmd = CMD_START_MEASUREMENT | (zyxt_flags & 0xf);
  return sendCommand(hall_sensor, cmd, io);
}

uint8_t readMeasurement(struct MLX90393 *hall_sensor, uint8_t zyxt_flags, struct io_descriptor *io)
{
  uint8_t cmd = CMD_READ_MEASUREMENT | (zyxt_flags & 0xf);
  
  i2c_m_sync_set_slaveaddr(&I2C_0, hall_sensor->I2C_address, I2C_M_SEVEN);

  int32_t ret;

  uint8_t buffer[9];
  uint8_t count = 1 + (((zyxt_flags & Z_FLAG)?2:0) +
                       ((zyxt_flags & Y_FLAG)?2:0) +
                       ((zyxt_flags & X_FLAG)?2:0) +
                       ((zyxt_flags & T_FLAG)?2:0) );

    ret = i2c_m_sync_cmd_write_easy(io, cmd, (uint8_t *)buffer, (uint16_t) count);
    
    if (ret < 1) {return STATUS_ERROR;}

  uint8_t i = 1;
  if (zyxt_flags & T_FLAG){
    hall_sensor->dataRaw.t =  ((uint16_t) buffer[i] <<8) | buffer[i+1];
    i += 2;
  } else {
    hall_sensor->dataRaw.t = 0;
  }
  if (zyxt_flags & X_FLAG){
    hall_sensor->dataRaw.x =  ((uint16_t) buffer[i] <<8) | buffer[i+1];
    i += 2;
  } else {
    hall_sensor->dataRaw.x = 0;
  }
  if (zyxt_flags & Y_FLAG){
    hall_sensor->dataRaw.y =  ((uint16_t) buffer[i] <<8) | buffer[i+1];
    i += 2;
  } else {
    hall_sensor->dataRaw.y = 0;
  }
  if (zyxt_flags & Z_FLAG){
    hall_sensor->dataRaw.z =  ((uint16_t) buffer[i] <<8) | buffer[i+1];
    i += 2;
  } else {
    hall_sensor->dataRaw.z = 0;
  }

  return buffer[0];
}

uint8_t memoryRecall(struct MLX90393 *hall_sensor, struct io_descriptor *io)
{
  cache_invalidate(hall_sensor);
  return sendCommand(hall_sensor, CMD_MEMORY_RECALL, io);
}

uint8_t memoryStore(struct MLX90393 *hall_sensor, struct io_descriptor *io)
{
  return sendCommand(hall_sensor, CMD_MEMORY_STORE, io);
}

void convertRaw(struct MLX90393 *hall_sensor)
{
  const uint8_t gain_sel = (hall_sensor->cache.reg[GAIN_SEL_REG] & GAIN_SEL_MASK) >> GAIN_SEL_SHIFT;
  const uint8_t hallconf = (hall_sensor->cache.reg[HALLCONF_REG] & HALLCONF_MASK) >> HALLCONF_SHIFT;
  const uint8_t res_xyz = (hall_sensor->cache.reg[RES_XYZ_REG] & RES_XYZ_MASK) >> RES_XYZ_SHIFT;
  const uint8_t res_x = (res_xyz >> 0) & 0x3;
  const uint8_t res_y = (res_xyz >> 2) & 0x3;
  const uint8_t res_z = (res_xyz >> 4) & 0x3;
  uint8_t tcmp_en = (hall_sensor->cache.reg[TCMP_EN_REG] & TCMP_EN_MASK) >> TCMP_EN_SHIFT;

  float xy_sens;
  float z_sens;

  switch(hallconf){
  default:
  case 0:
    xy_sens = hall_sensor->base_xy_sens_hc0;
    z_sens = hall_sensor->base_z_sens_hc0;
    break;
  case 0xc:
    xy_sens = hall_sensor->base_xy_sens_hc0xc;
    z_sens = hall_sensor->base_z_sens_hc0xc;
    break;
  }

  float gain_factor = hall_sensor->gain_multipliers[gain_sel & 0x7];

  if (tcmp_en){
    hall_sensor->data.x = ( (hall_sensor->dataRaw.x - 32768.f) * xy_sens *
               gain_factor * (1 << res_x) );
  } else {
    switch(res_x){
    case 0:
		hall_sensor->data.x = (int16_t) hall_sensor->dataRaw.x * xy_sens * gain_factor * (1 << res_x);
		break;
    case 1:
      hall_sensor->data.x = (int16_t) hall_sensor->dataRaw.x * xy_sens * gain_factor * (1 << res_x);
      break;
    case 2:
      hall_sensor->data.x = ( (hall_sensor->dataRaw.x - 32768.f) * xy_sens *
                 gain_factor * (1 << res_x) );
      break;
    case 3:
      hall_sensor->data.x = ( (hall_sensor->dataRaw.x - 16384.f) * xy_sens *
                 gain_factor * (1 << res_x) );
      break;
    }
  }

  if (tcmp_en){
    hall_sensor->data.y = ( (hall_sensor->dataRaw.y - 32768.f) * xy_sens *
               gain_factor * (1 << res_y) );
  } else {
    switch(res_y){
    case 0:
		hall_sensor->data.y = (int16_t) hall_sensor->dataRaw.y * xy_sens * gain_factor * (1 << res_y);
		break;
    case 1:
      hall_sensor->data.y = (int16_t) hall_sensor->dataRaw.y * xy_sens * gain_factor * (1 << res_y);
      break;
    case 2:
      hall_sensor->data.y = ( (hall_sensor->dataRaw.y - 32768.f) * xy_sens *
                 gain_factor * (1 << res_y) );
      break;
    case 3:
      hall_sensor->data.y = ( (hall_sensor->dataRaw.y - 16384.f) * xy_sens *
                 gain_factor * (1 << res_y) );
      break;
    }
  }

  if (tcmp_en){
    hall_sensor->data.z = ( (hall_sensor->dataRaw.z - 32768.f) * z_sens *
               gain_factor * (1 << res_z) );
  } else {
    switch(res_z){
    case 0:
		hall_sensor->data.z = (int16_t) hall_sensor->dataRaw.z * z_sens * gain_factor * (1 << res_z);
		break;
    case 1:
      hall_sensor->data.z = (int16_t) hall_sensor->dataRaw.z * z_sens * gain_factor * (1 << res_z);
      break;
    case 2:
      hall_sensor->data.z = ( (hall_sensor->dataRaw.z - 32768.f) * z_sens *
                 gain_factor * (1 << res_z) );
      break;
    case 3:
      hall_sensor->data.z = ( (hall_sensor->dataRaw.z - 16384.f) * z_sens *
                 gain_factor * (1 << res_z) );
      break;
    }
  }

  hall_sensor->data.t = 25 + (hall_sensor->dataRaw.t - 46244.f)/45.2f;
  
  if (hall_sensor->data.x >50000)
  {
	  hall_sensor->data.x = 50000;
  }
  else 
  {
	  if (hall_sensor->data.x < -50000)
	  {
		  hall_sensor->data.x = -50000;
	  }
  }
    if (hall_sensor->data.y > 50000)
    {
	    hall_sensor->data.y = 50000;
    }
    else
    {
	    if (hall_sensor->data.y < -50000)
	    {
		    hall_sensor->data.y = -50000;
	    }
    }
    if (hall_sensor->data.z > 50000)
    {
	    //hall_sensor->data.z = 50000;
    }
    else
    {
	    if (hall_sensor->data.z < -50000)
	    {
		    //hall_sensor->data.z = -50000;
	    }
    }
}

uint16_t convDelayMillis(struct MLX90393 *hall_sensor) {
  const uint8_t osr = (hall_sensor->cache.reg[OSR_REG] & OSR_MASK) >> OSR_SHIFT;
  const uint8_t osr2 = (hall_sensor->cache.reg[OSR2_REG] & OSR2_MASK) >> OSR2_SHIFT;
  const uint8_t dig_flt = (hall_sensor->cache.reg[DIG_FLT_REG] & DIG_FLT_MASK) >> DIG_FLT_SHIFT;
  const uint8_t magnetic_axis = 3;
  
  uint32_t delayTimeMicro = (magnetic_axis * (((2 + (1 << dig_flt)) * (1 << osr) *64) + 67)) + ((192*(1<<osr2)) + 67) ; 
  uint16_t delaytimeMilli = (delayTimeMicro / 1000) + 2; 

	/*(hall_sensor->DRDY_pin == true)? 0  //no delay if drdy pin present  :
                     // estimate conversion time from datasheet equations
                     ( 3 * (2 + (1 << dig_flt)) * (1 << osr) *0.064f +
                      (1 << osr2) * 0.192f ) *
                       1.3f;  // 30% tolerance
					   
					   */
	return delaytimeMilli;
}

uint16_t convDelayMicro(struct MLX90393 *hall_sensor) {
  const uint8_t osr = (hall_sensor->cache.reg[OSR_REG] & OSR_MASK) >> OSR_SHIFT;
  const uint8_t osr2 = (hall_sensor->cache.reg[OSR2_REG] & OSR2_MASK) >> OSR2_SHIFT;
  const uint8_t dig_flt = (hall_sensor->cache.reg[DIG_FLT_REG] & DIG_FLT_MASK) >> DIG_FLT_SHIFT;
  const uint8_t magnetic_axis = 3;
  
  uint32_t delayTimeMicro = (magnetic_axis * (((2 + (1 << dig_flt)) * (1 << osr) *64) + 67)) + ((192*(1<<osr2)) + 67) ; 
  uint16_t delayTimeMicro_final = delayTimeMicro/100 + 8; 

	/*(hall_sensor->DRDY_pin == true)? 0  //no delay if drdy pin present  :
                     // estimate conversion time from datasheet equations
                     ( 3 * (2 + (1 << dig_flt)) * (1 << osr) *0.064f +
                      (1 << osr2) * 0.192f ) *
                       1.3f;  // 30% tolerance
					   
					   */
	return delayTimeMicro_final;
}

uint8_t readData(struct MLX90393 *hall_sensor, struct io_descriptor *io)
{
  uint8_t status1 = startMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG | T_FLAG, io);

  // wait for DRDY signal if connected, otherwise delay appropriately
  if (hall_sensor->DRDY_pin == true){
    /* implement your own interupt functionality)
	delay_us(600);
    while(!gpio_get_pin_level(INT)){
      // busy wait
    }
	*/
  } else {
    delay_ms(convDelayMillis(hall_sensor));
  }

  uint8_t status2 = readMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG | T_FLAG, io);
  convertRaw(hall_sensor);
  return checkStatus(status1) | checkStatus(status2);
}

//checks 
bool isOK(uint8_t status)
{
  return (status & ERROR_BIT) == 0;
}

bool hasError(uint8_t status)
{
  return (status & ERROR_BIT) != 0;
}

uint8_t checkStatus(uint8_t status)
{
  return (status & ERROR_BIT) ? STATUS_ERROR : STATUS_OK;
}