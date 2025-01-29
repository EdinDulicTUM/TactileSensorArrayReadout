#ifndef MLX90393_H_INCLUDED
#define MLX90393_H_INCLUDED

#include <stdint.h>
#include <driver_init.h>
#include <hal_io.h>

  enum { STATUS_OK = 0, STATUS_ERROR = 0xff } return_status_t;
  enum { Z_FLAG = 0x8, Y_FLAG = 0x4, X_FLAG = 0x2, T_FLAG = 0x1 } axis_flag_t;
  enum {I2C_PREFIX_011 = 0x03, I2C_PREFIX_012 = 0x04, I2C_PREFIX_013 = 0x05, 
        I2C_PREFIX_014 = 0x06 }; //Modified from Original; Prefix according to Ordering Code
  enum { I2C_BASE_ADDR = 0x0c };
  enum { GAIN_SEL_REG = 0x0, GAIN_SEL_MASK = 0x0070, GAIN_SEL_SHIFT = 4 };
  enum { HALLCONF_REG = 0x0, HALLCONF_MASK = 0x000f, HALLCONF_SHIFT = 0 };
  enum { BURST_SEL_REG = 0x1, BURST_SEL_MASK = 0x03c0, BURST_SEL_SHIFT = 6};
  enum { TRIG_INT_SEL_REG = 0x1, TRIG_INT_SEL_MASK = 0x8000, TRIG_INT_SEL_SHIFT = 15 };
  enum { EXT_TRIG_REG = 0x1, EXT_TRIG_MASK = 0x0800, EXT_TRIG_SHIFT = 11 };
  enum { OSR_REG = 0x2, OSR_MASK = 0x0003, OSR_SHIFT = 0 };
  enum { OSR2_REG = 0x2, OSR2_MASK = 0x1800, OSR2_SHIFT = 11 };
  enum { DIG_FLT_REG = 0x2, DIG_FLT_MASK = 0x001c, DIG_FLT_SHIFT = 2 };
  enum { RES_XYZ_REG = 0x2, RES_XYZ_MASK = 0x07e0, RES_XYZ_SHIFT = 5 };
  enum { TCMP_EN_REG = 0x1, TCMP_EN_MASK = 0x0400, TCMP_EN_SHIFT = 10 };
  enum { X_OFFSET_REG = 4, Y_OFFSET_REG = 5, Z_OFFSET_REG = 6 };
  enum { WOXY_THRESHOLD_REG = 7, WOZ_THRESHOLD_REG = 8, WOT_THRESHOLD_REG = 9 };
  enum { BURST_MODE_BIT = 0x80, WAKE_ON_CHANGE_BIT = 0x40,
         POLLING_MODE_BIT = 0x20, ERROR_BIT = 0x10, EEC_BIT = 0x08,
         RESET_BIT = 0x04, D1_BIT = 0x02, D0_BIT = 0x01 };

  enum {
    CMD_NOP = 0x00,
    CMD_EXIT = 0x80,
    CMD_START_BURST = 0x10,
    CMD_WAKE_ON_CHANGE = 0x20,
    CMD_START_MEASUREMENT = 0x30,
    CMD_READ_MEASUREMENT = 0x40,
    CMD_READ_REGISTER = 0x50,
    CMD_WRITE_REGISTER = 0x60,
    CMD_MEMORY_RECALL = 0xd0,
    CMD_MEMORY_STORE = 0xe0,
    CMD_RESET = 0xf0
  };

  struct txyz
  {
    float t;
    float x;
    float y;
    float z;
  };

  struct txyzRaw
  {
    uint16_t t;
    uint16_t x;
    uint16_t y;
    uint16_t z;
  };

  enum { CACHESIZE = 3, ALL_DIRTY_MASK = 1 << ((CACHESIZE + 1) - 1)};
  
  struct cache_t {
    uint8_t dirty;
    uint16_t reg[CACHESIZE];
  };

  //struct io_descriptor *bmx_io;

  struct MLX90393
  {
    uint8_t I2C_address;
    uint8_t I2C_prefix;
    bool DRDY_pin;
    int order_code_last_digit;
    float gain_multipliers[8];
    float base_xy_sens_hc0;
    float base_z_sens_hc0;
    float base_xy_sens_hc0xc;
    float base_z_sens_hc0xc;
    struct cache_t cache;
    struct txyzRaw dataRaw;
    struct txyz data;
  };

    // raw device commands
  uint8_t exit_command(struct MLX90393 *hall_sensor, struct io_descriptor *io);
  uint8_t startBurst(struct MLX90393 *hall_sensor, uint8_t zyxt_flags, struct io_descriptor *io);
  uint8_t startWakeOnChange(struct MLX90393 *hall_sensor, uint8_t zyxt_flags, struct io_descriptor *io);
  uint8_t startMeasurement(struct MLX90393 *hall_sensor, uint8_t zyxt_flags, struct io_descriptor *io);
  uint8_t readMeasurement(struct MLX90393 *hall_sensor, uint8_t zyxt_flags, struct io_descriptor *io);
  uint8_t readRegister(struct MLX90393 *hall_sensor, uint8_t address, uint16_t *data, struct io_descriptor *io);
  int32_t i2c_m_sync_reg_read_easy(struct io_descriptor *io, uint8_t cmd, uint8_t reg, const uint8_t *const buf_answer, const uint16_t length_answer);
  uint8_t writeRegister(struct MLX90393 *hall_sensor, uint8_t address, uint16_t data, struct io_descriptor *io);
  int32_t i2c_m_sync_reg_write_easy(struct io_descriptor *io, uint8_t cmd, uint16_t data, uint8_t reg, const uint8_t *const buf_answer);
  uint8_t reset(struct MLX90393 *hall_sensor, struct io_descriptor *io);
  uint8_t memoryRecall(struct MLX90393 *hall_sensor,struct io_descriptor *io);
  uint8_t memoryStore(struct MLX90393 *hall_sensor, struct io_descriptor *io);
  uint8_t nop(struct MLX90393 *hall_sensor, struct io_descriptor *io);
  uint8_t sendCommand(struct MLX90393 *hall_sensor, uint8_t cmd, struct io_descriptor *io);
  int32_t i2c_m_sync_cmd_write_easy(struct io_descriptor *io, const uint8_t cmd, const uint8_t *const buf_answer, const uint16_t length_answer);
  uint8_t checkStatus(uint8_t status);
  bool isOK(uint8_t status);
  bool hasError(uint8_t status);
  void convertRaw(struct MLX90393 *hall_sensor);
  uint16_t convDelayMillis(struct MLX90393 *hall_sensor);

 // higher-level API
  uint8_t select_prefix(struct MLX90393 *hall_sensor, int order_code_last_digit);
  void initialize(struct MLX90393 *hall_sensor);
  uint8_t begin(struct MLX90393 *hall_sensor, int order_code_last_digit, uint8_t A1, uint8_t A0, bool DRDY, struct io_descriptor *io); 

  // returns B (x,y,z) in uT, temperature in C
  uint8_t readData(struct MLX90393 *hall_sensor, struct io_descriptor *io);
  uint8_t setGainSel(struct MLX90393 *hall_sensor, uint8_t gain_sel, struct io_descriptor *io);
  uint8_t getGainSel(struct MLX90393 *hall_sensor, uint8_t gain_sel, struct io_descriptor *io);
  uint8_t setHallConf(struct MLX90393 *hall_sensor, uint8_t hallconf, struct io_descriptor *io);
  uint8_t getHallConf(struct MLX90393 *hall_sensor, uint8_t hallconf, struct io_descriptor *io);
  uint8_t setBurstSel(struct MLX90393 *hall_sensor, uint8_t burst_sel, struct io_descriptor *io);
  uint8_t getBurstSel(struct MLX90393 *hall_sensor, uint8_t burst_sel, struct io_descriptor *io);
  uint8_t setExtTrig(struct MLX90393 *hall_sensor, int8_t ext_trig, struct io_descriptor *io);
  uint8_t getExtTrig(struct MLX90393 *hall_sensor, uint8_t ext_trig, struct io_descriptor *io);
  uint8_t setTrigIntSel(struct MLX90393 *hall_sensor, uint8_t trig_int_sel, struct io_descriptor *io);
  uint8_t getTrigIntSel(struct MLX90393 *hall_sensor, uint8_t trig_int_sel, struct io_descriptor *io);
  uint8_t setOverSampling(struct MLX90393 *hall_sensor, uint8_t osr, struct io_descriptor *io);
  uint8_t getOverSampling(struct MLX90393 *hall_sensor, uint8_t osr, struct io_descriptor *io);
  uint8_t setTemperatureOverSampling(struct MLX90393 *hall_sensor, uint8_t osr2, struct io_descriptor *io);
  uint8_t getTemperatureOverSampling(struct MLX90393 *hall_sensor, uint8_t osr2, struct io_descriptor *io);
  uint8_t setDigitalFiltering(struct MLX90393 *hall_sensor, uint8_t dig_flt, struct io_descriptor *io);
  uint8_t getDigitalFiltering(struct MLX90393 *hall_sensor, uint8_t dig_flt, struct io_descriptor *io);
  uint8_t setResolution(struct MLX90393 *hall_sensor, uint8_t res_x, uint8_t res_y, uint8_t res_z, struct io_descriptor *io);
  uint8_t getResolution(struct MLX90393 *hall_sensor, uint8_t res_x, uint8_t res_y, uint8_t res_z, struct io_descriptor *io);
  uint8_t setTemperatureCompensation(struct MLX90393 *hall_sensor, uint8_t enabled, struct io_descriptor *io);
  uint8_t getTemperatureCompensation(struct MLX90393 *hall_sensor, uint8_t enabled, struct io_descriptor *io);
  uint8_t setOffsets(struct MLX90393 *hall_sensor, uint16_t x, uint16_t y, uint16_t z, struct io_descriptor *io);
  uint8_t setWOXYThreshold(struct MLX90393 *hall_sensor, uint16_t woxy_thresh, struct io_descriptor *io);
  uint8_t setWOZThreshold(struct MLX90393 *hall_sensor, uint16_t woz_thresh, struct io_descriptor *io);
  uint8_t setWOTThreshold(struct MLX90393 *hall_sensor, uint16_t wot_thresh, struct io_descriptor *io);

  // parameters are cached to avoid reading them from sensor unnecessarily
  void cache_invalidate(struct MLX90393 *hall_sensor);
  void cache_invalidate_address(struct MLX90393 *hall_sensor, uint8_t address);
  void cache_set(struct MLX90393 *hall_sensor, uint8_t address, uint16_t data);
  uint8_t cache_fill(struct MLX90393 *hall_sensor, struct io_descriptor *io);



#endif