/*
 * CFile1.c
 *
 * Created: 28.08.2025 15:26:53
 *  Author: dulic
 */ 

#include <Melexis/Calibration_Parameters.h>


void initialize_calibration_parameters(struct function_Parameters *parameters_array, uint8_t array_select)
{
	switch(array_select){
		case 1: ;
			// SensorArray 1 Parameters - Sensor Number 4 --------------------------------------------------------------------------------
			// SensorArray 1 Left Row - Top Sensor - X Direction 
			parameters_array->sensor_topLeft[0][0] = 1.25276464352330e-13;
			parameters_array->sensor_topLeft[1][0] = 3.90599677451257e-14;
			parameters_array->sensor_topLeft[2][0] = 1.75715117218414e-13;
			parameters_array->sensor_topLeft[3][0] = -6.19789719357561e-09;
			parameters_array->sensor_topLeft[4][0] = 4.67971922447968e-13;
			parameters_array->sensor_topLeft[5][0] = -3.41594654231982e-13;
			parameters_array->sensor_topLeft[6][0] = -4.90684153867589e-09;
			parameters_array->sensor_topLeft[7][0] = -1.22482665990801e-13;
			parameters_array->sensor_topLeft[8][0] = -1.51378486695813e-08;
			parameters_array->sensor_topLeft[9][0] = -0.000479270826019068;
			parameters_array->sensor_topLeft[10][0] = -6.97649646602250e-14;
			parameters_array->sensor_topLeft[11][0] = -4.03553595657184e-13;
			parameters_array->sensor_topLeft[12][0] = -1.46030586989790e-08;
			parameters_array->sensor_topLeft[13][0] = -2.92753443970443e-13;
			parameters_array->sensor_topLeft[14][0] = -1.09307012051624e-08;
			parameters_array->sensor_topLeft[15][0] = -9.17187720498957e-05;
			parameters_array->sensor_topLeft[16][0] = 8.33105284283181e-14;
			parameters_array->sensor_topLeft[17][0] = 3.11489406258029e-09;
			parameters_array->sensor_topLeft[18][0] = 0.000103086901986412;
			parameters_array->sensor_topLeft[19][0] = 0.848337455230125;
			
			// SensorArray 1 Left Row - Middle Sensor - X Direction 
			parameters_array->sensor_middleLeft[0][0] = -2.02041591394221e-13;
			parameters_array->sensor_middleLeft[1][0] = 2.30103679975263e-14;
			parameters_array->sensor_middleLeft[2][0] = -2.23048253714814e-13;
			parameters_array->sensor_middleLeft[3][0] = -3.71090244452286e-09;
			parameters_array->sensor_middleLeft[4][0] = 5.20762735285505e-13;
			parameters_array->sensor_middleLeft[5][0] = -8.53101864297645e-14	;
			parameters_array->sensor_middleLeft[6][0] = -9.89126137560679e-10;
			parameters_array->sensor_middleLeft[7][0] = -1.64366166904235e-13;
			parameters_array->sensor_middleLeft[8][0] = -1.73872806804545e-08;
			parameters_array->sensor_middleLeft[9][0] = -0.000509813398624398;
			parameters_array->sensor_middleLeft[10][0] = -3.45899440928606e-14;
			parameters_array->sensor_middleLeft[11][0] = 1.90950394241020e-13;
			parameters_array->sensor_middleLeft[12][0] = 1.27645558311751e-09;
			parameters_array->sensor_middleLeft[13][0] = -9.24884883383531e-14;
			parameters_array->sensor_middleLeft[14][0] = -2.92959871573016e-09;
			parameters_array->sensor_middleLeft[15][0] = -1.68070580501177e-05;
			parameters_array->sensor_middleLeft[16][0] = -8.68586957962114e-15;
			parameters_array->sensor_middleLeft[17][0] = -1.48388032075104e-09;
			parameters_array->sensor_middleLeft[18][0] = -2.61448655750350e-05;
			parameters_array->sensor_middleLeft[19][0] = 0.163951345864922;

			// SensorArray 1 Left Row - Bottom Sensor - X Direction 
			parameters_array->sensor_bottomLeft[0][0] = 1.94106185292460e-13;
			parameters_array->sensor_bottomLeft[1][0] = 1.41932895373573e-13;
			parameters_array->sensor_bottomLeft[2][0] = -2.19643463581156e-13;
			parameters_array->sensor_bottomLeft[3][0] = 9.10235993106918e-10;
			parameters_array->sensor_bottomLeft[4][0] = 5.18940076663233e-13;
			parameters_array->sensor_bottomLeft[5][0] = -4.42786669597697e-13;
			parameters_array->sensor_bottomLeft[6][0] = -8.18777954037397e-09;
			parameters_array->sensor_bottomLeft[7][0] = -1.04908059217805e-13;
			parameters_array->sensor_bottomLeft[8][0] = -1.36854662000252e-08;
			parameters_array->sensor_bottomLeft[9][0] = -0.000467782919124426;
			parameters_array->sensor_bottomLeft[10][0] = 2.22441335752011e-14;
			parameters_array->sensor_bottomLeft[11][0] = 1.88757246135066e-13;
			parameters_array->sensor_bottomLeft[12][0] = 6.84334606428272e-09;
			parameters_array->sensor_bottomLeft[13][0] = 2.83214499447420e-13;
			parameters_array->sensor_bottomLeft[14][0] = 1.08243302343709e-08;
			parameters_array->sensor_bottomLeft[15][0] = 0.000101897642072940;
			parameters_array->sensor_bottomLeft[16][0] = -2.04000410555316e-13;
			parameters_array->sensor_bottomLeft[17][0] = -1.10885952445752e-08;
			parameters_array->sensor_bottomLeft[18][0] = -0.000235938951237971;
			parameters_array->sensor_bottomLeft[19][0] = -1.48368297705417;

			// SensorArray 1 Left Row - Top Sensor - Y Direction 
			parameters_array->sensor_topLeft[0][1] = 1.25276464352330e-13;
			parameters_array->sensor_topLeft[1][1] = 3.90599677451257e-14;
			parameters_array->sensor_topLeft[2][1] = 1.75715117218414e-13;
			parameters_array->sensor_topLeft[3][1] = -6.19789719357561e-09;
			parameters_array->sensor_topLeft[4][1] = 4.67971922447968e-13;
			parameters_array->sensor_topLeft[5][1] = -3.41594654231982e-13;
			parameters_array->sensor_topLeft[6][1] = -4.90684153867589e-09;
			parameters_array->sensor_topLeft[7][1] = -1.22482665990801e-13;
			parameters_array->sensor_topLeft[8][1] = -1.51378486695813e-08;
			parameters_array->sensor_topLeft[9][1] = -0.000479270826019068;
			parameters_array->sensor_topLeft[10][1] = -6.97649646602250e-14;
			parameters_array->sensor_topLeft[11][1] = -4.03553595657184e-13;
			parameters_array->sensor_topLeft[12][1] = -1.46030586989790e-08;
			parameters_array->sensor_topLeft[13][1] = -2.92753443970443e-13;
			parameters_array->sensor_topLeft[14][1] = -1.09307012051624e-08;
			parameters_array->sensor_topLeft[15][1] = -9.17187720498957e-05;
			parameters_array->sensor_topLeft[16][1] = 8.33105284283181e-14;
			parameters_array->sensor_topLeft[17][1] = 3.11489406258029e-09;
			parameters_array->sensor_topLeft[18][1] = 0.000103086901986412;
			parameters_array->sensor_topLeft[19][1] = 0.848337455230125;
			
			// SensorArray 1 Left Row - Middle Sensor - Y Direction 
			parameters_array->sensor_middleLeft[0][1] = 2.53730078109932e-13;
			parameters_array->sensor_middleLeft[1][1] = 6.60722884883581e-13;
			parameters_array->sensor_middleLeft[2][1] = -5.04857107094855e-13;
			parameters_array->sensor_middleLeft[3][1] = -4.89642323764466e-09;
			parameters_array->sensor_middleLeft[4][1] = 1.65812350514254e-13;
			parameters_array->sensor_middleLeft[5][1] = 6.62699007040621e-13;
			parameters_array->sensor_middleLeft[6][1] = 8.63037457077357e-09;
			parameters_array->sensor_middleLeft[7][1] = -5.56658347236268e-14;
			parameters_array->sensor_middleLeft[8][1] = -2.57858180526061e-10;
			parameters_array->sensor_middleLeft[9][1] = 4.18608962845497e-06;
			parameters_array->sensor_middleLeft[10][1] = -1.81989254543360e-14;
			parameters_array->sensor_middleLeft[11][1] = -1.36009830837230e-13;
			parameters_array->sensor_middleLeft[12][1] = -1.01125127055913e-12;
			parameters_array->sensor_middleLeft[13][1] = -7.61628001430015e-14;
			parameters_array->sensor_middleLeft[14][1] = -1.88399075499996e-08;
			parameters_array->sensor_middleLeft[15][1] = -0.000520197416675857;
			parameters_array->sensor_middleLeft[16][1] = -3.72174233979599e-13;
			parameters_array->sensor_middleLeft[17][1] = -1.55167181160463e-08;
			parameters_array->sensor_middleLeft[18][1] = -0.000229822985205763;
			parameters_array->sensor_middleLeft[19][1] = -1.09021045027509;
			
			// SensorArray 1 Left Row - Bottom Sensor - Y Direction 
			parameters_array->sensor_bottomLeft[0][1] = 4.31840328224511e-13;
			parameters_array->sensor_bottomLeft[1][1] = 4.93858086496804e-13;
			parameters_array->sensor_bottomLeft[2][1] = 1.91400540474537e-14;
			parameters_array->sensor_bottomLeft[3][1] = 1.58830633213099e-09;
			parameters_array->sensor_bottomLeft[4][1] = 1.50711030618265e-14;
			parameters_array->sensor_bottomLeft[5][1] = 6.14284511402242e-13;
			parameters_array->sensor_bottomLeft[6][1] = 9.13532223482444e-09;
			parameters_array->sensor_bottomLeft[7][1] = 1.51087871875397e-14;
			parameters_array->sensor_bottomLeft[8][1] = -5.71827801205314e-10;
			parameters_array->sensor_bottomLeft[9][1] = -2.45966853496243e-05;
			parameters_array->sensor_bottomLeft[10][1] = -1.66212803038651e-13;
			parameters_array->sensor_bottomLeft[11][1] = 8.79307929989398e-15;
			parameters_array->sensor_bottomLeft[12][1] = 3.40664661050576e-09;
			parameters_array->sensor_bottomLeft[13][1] = -2.38096980784775e-13;
			parameters_array->sensor_bottomLeft[14][1] = -2.48489558078509e-08;
			parameters_array->sensor_bottomLeft[15][1] = -0.000582439296353274;
			parameters_array->sensor_bottomLeft[16][1] = -1.21847336403809e-13;
			parameters_array->sensor_bottomLeft[17][1] = -4.37111919003833e-09;
			parameters_array->sensor_bottomLeft[18][1] = -6.28535384708850e-05;
			parameters_array->sensor_bottomLeft[19][1] = -0.157464689500466;

			// SensorArray 1 Left Row - Top Sensor - Z Direction
			parameters_array->sensor_topLeft[0][2] = 1.08952279965549e-12;
			parameters_array->sensor_topLeft[1][2] = -9.78382452742249e-14;
			parameters_array->sensor_topLeft[2][2] = 5.01999455381403e-12;
			parameters_array->sensor_topLeft[3][2] = 1.92247859623603e-07;
			parameters_array->sensor_topLeft[4][2] = -7.17173154321311e-13;
			parameters_array->sensor_topLeft[5][2] = 9.73551099592821e-13;
			parameters_array->sensor_topLeft[6][2] = 1.74089622010683e-08;
			parameters_array->sensor_topLeft[7][2] = -6.74568221354830e-15;
			parameters_array->sensor_topLeft[8][2] = -4.61452737815286e-09;
			parameters_array->sensor_topLeft[9][2] = -0.000149961193505933;
			parameters_array->sensor_topLeft[10][2] = -4.31801251034167e-13;
			parameters_array->sensor_topLeft[11][2] = 4.67487808568481e-12;
			parameters_array->sensor_topLeft[12][2] = 1.86154985434309e-07;
			parameters_array->sensor_topLeft[13][2] = 2.17353898683215e-12;
			parameters_array->sensor_topLeft[14][2] = 8.04034072660032e-08;
			parameters_array->sensor_topLeft[15][2] = 0.000724772323886507;
			parameters_array->sensor_topLeft[16][2] = 2.04045460234050e-12;
			parameters_array->sensor_topLeft[17][2] = 1.18143639269362e-07;
			parameters_array->sensor_topLeft[18][2] = 0.00123673262706410;
			parameters_array->sensor_topLeft[19][2] = 2.72006952506292;
			
			// SensorArray 1 Left Row - Middle Sensor - Z Direction
			parameters_array->sensor_middleLeft[0][2] = 2.47445827351136e-13;
			parameters_array->sensor_middleLeft[1][2] = 1.86913367230467e-13;
			parameters_array->sensor_middleLeft[2][2] = 5.69436765562210e-12;
			parameters_array->sensor_middleLeft[3][2] = 2.08003168017841e-07;
			parameters_array->sensor_middleLeft[4][2] = 2.55639221209814e-13;
			parameters_array->sensor_middleLeft[5][2] = -1.03805686237307e-12;
			parameters_array->sensor_middleLeft[6][2] = -1.91112083324539e-08;
			parameters_array->sensor_middleLeft[7][2] = -2.04033853852490e-13;
			parameters_array->sensor_middleLeft[8][2] = -1.26348392258338e-08;
			parameters_array->sensor_middleLeft[9][2] = -0.000241004591326337;
			parameters_array->sensor_middleLeft[10][2] = -5.75616308706831e-13;
			parameters_array->sensor_middleLeft[11][2] = 3.02199957330102e-12;
			parameters_array->sensor_middleLeft[12][2] = 1.67944594781800e-07;
			parameters_array->sensor_middleLeft[13][2] = 1.21511709662635e-12;
			parameters_array->sensor_middleLeft[14][2] = 4.83469945993984e-08;
			parameters_array->sensor_middleLeft[15][2] = 0.000416117443869195;
			parameters_array->sensor_middleLeft[16][2] = 2.50563690053829e-12;
			parameters_array->sensor_middleLeft[17][2] = 1.42690090701721e-07;
			parameters_array->sensor_middleLeft[18][2] = 0.00159050451603903;
			parameters_array->sensor_middleLeft[19][2 ]= 4.30838480287426;
			
			// SensorArray 1 Left Row - Bottom Sensor - Z Direction
			parameters_array->sensor_bottomLeft[0][2] = -1.22026948576594e-13;
			parameters_array->sensor_bottomLeft[1][2] = 6.92109211319232e-13;
			parameters_array->sensor_bottomLeft[2][2] = 4.53709672132938e-12;
			parameters_array->sensor_bottomLeft[3][2] = 1.75691221417336e-07;
			parameters_array->sensor_bottomLeft[4][2] = 2.05853888091656e-12;
			parameters_array->sensor_bottomLeft[5][2] = -1.51154240473708e-12;
			parameters_array->sensor_bottomLeft[6][2] = -3.28581158050416e-08;
			parameters_array->sensor_bottomLeft[7][2] = 1.58162930148036e-12;
			parameters_array->sensor_bottomLeft[8][2] = 5.84259585518410e-08;
			parameters_array->sensor_bottomLeft[9][2] = 0.000574021932326809;
			parameters_array->sensor_bottomLeft[10][2] = -2.61503721435232e-13;
			parameters_array->sensor_bottomLeft[11][2] = 2.45787836233694e-12;
			parameters_array->sensor_bottomLeft[12][2] = 1.39154838139716e-07;
			parameters_array->sensor_bottomLeft[13][2] = 1.58237795450006e-12;
			parameters_array->sensor_bottomLeft[14][2] = 6.67428749409587e-08;
			parameters_array->sensor_bottomLeft[15][2] = 0.000654406114895380;
			parameters_array->sensor_bottomLeft[16][2] = 1.19491351710700e-12;
			parameters_array->sensor_bottomLeft[17][2] = 7.02920063584498e-08;
			parameters_array->sensor_bottomLeft[18][2] = 0.000404822844731237;
			parameters_array->sensor_bottomLeft[19][2] = -2.35368052541171;

			// SensorArray 1 Middle Row - Top Sensor - X Direction
			parameters_array->sensor_topMiddle[0][0] = 1.02854918946006e-12;
			parameters_array->sensor_topMiddle[1][0] = 1.52797666322582e-12;
			parameters_array->sensor_topMiddle[2][0] = 3.51492073863149e-13;
			parameters_array->sensor_topMiddle[3][0] = -8.45332694302957e-09;
			parameters_array->sensor_topMiddle[4][0] = 2.35427757394128e-141;
			parameters_array->sensor_topMiddle[5][0] = 4.37845090131627e-13;
			parameters_array->sensor_topMiddle[6][0] = 9.59225611272234e-09;
			parameters_array->sensor_topMiddle[7][0] = -5.47593276536740e-13;
			parameters_array->sensor_topMiddle[8][0] = -3.11279885488603e-08;
			parameters_array->sensor_topMiddle[9][0] = -0.000691504049290309;
			parameters_array->sensor_topMiddle[10][0] = 1.46845652135683e-12;
			parameters_array->sensor_topMiddle[11][0] = -1.04441929339939e-13;
			parameters_array->sensor_topMiddle[12][0] = -9.29840097125406e-09;
			parameters_array->sensor_topMiddle[13][0] = 1.04601629784661e-13;
			parameters_array->sensor_topMiddle[14][0] = -1.01788370243564e-09;
			parameters_array->sensor_topMiddle[15][0] = -4.06410595963716e-05;
			parameters_array->sensor_topMiddle[16][0] = -4.94414482108941e-13;
			parameters_array->sensor_topMiddle[17][0] = -3.58762894713167e-08;
			parameters_array->sensor_topMiddle[18][0] = -0.000664187977533756;
			parameters_array->sensor_topMiddle[19][0] = -3.22143367645218;
			
			// SensorArray 1 Middle Row - Middle Sensor - X Direction
			parameters_array->sensor_middleMiddle[0][0] = -2.54752315629205e-14;
			parameters_array->sensor_middleMiddle[1][0] = 7.63401657663545e-14;
			parameters_array->sensor_middleMiddle[2][0] = -3.32946980552996e-13;
			parameters_array->sensor_middleMiddle[3][0] = -7.92103607712918e-09;
			parameters_array->sensor_middleMiddle[4][0] = 6.99325583558563e-13;
			parameters_array->sensor_middleMiddle[5][0] = 5.58882575735533e-13;
			parameters_array->sensor_middleMiddle[6][0] = 1.35529419123151e-08;
			parameters_array->sensor_middleMiddle[7][0] = 7.93324551903647e-14;
			parameters_array->sensor_middleMiddle[8][0] = -1.10706709466510e-08;
			parameters_array->sensor_middleMiddle[9][0] = -0.000536150630518398;
			parameters_array->sensor_middleMiddle[10][0] = 1.95606465127978e-13;
			parameters_array->sensor_middleMiddle[11][0] = 7.17023621475737e-14;
			parameters_array->sensor_middleMiddle[12][0] = -7.59142638137181e-10;
			parameters_array->sensor_middleMiddle[13][0] = 6.79751259414843e-14;
			parameters_array->sensor_middleMiddle[14][0] = 2.16877034648468e-09;
			parameters_array->sensor_middleMiddle[15][0] = 2.41015469789614e-05;
			parameters_array->sensor_middleMiddle[16][0] = -8.49114330496904e-15;
			parameters_array->sensor_middleMiddle[17][0] = -2.29764606682051e-09;
			parameters_array->sensor_middleMiddle[18][0] = -4.81108579493505e-05;
			parameters_array->sensor_middleMiddle[19][0] = -0.0360907026899464;
			
			// SensorArray 1 Middle Row - Bottom Sensor - X Direction
			parameters_array->sensor_bottomMiddle[0][0] = 1.30592194562420e-12;
			parameters_array->sensor_bottomMiddle[1][0] = -4.70570803600770e-13;
			parameters_array->sensor_bottomMiddle[2][0] = 4.19629144620383e-14;
			parameters_array->sensor_bottomMiddle[3][0] = 3.13198965923290e-09;
			parameters_array->sensor_bottomMiddle[4][0] = 2.35384503433769e-13;
			parameters_array->sensor_bottomMiddle[5][0] = 1.73898290285410e-13;
			parameters_array->sensor_bottomMiddle[6][0] = 5.30128456805481e-09;
			parameters_array->sensor_bottomMiddle[7][0] = -3.64567286934684e-13;
			parameters_array->sensor_bottomMiddle[8][0] = -2.53780488472188e-08;
			parameters_array->sensor_bottomMiddle[9][0] = -0.000644137042935365;
			parameters_array->sensor_bottomMiddle[10][0] = -1.74318471948367e-13;
			parameters_array->sensor_bottomMiddle[11][0] = 8.93852801213209e-13;
			parameters_array->sensor_bottomMiddle[12][0] = 2.74688048428889e-08;
			parameters_array->sensor_bottomMiddle[13][0] = -1.63537290192526e-13;
			parameters_array->sensor_bottomMiddle[14][0] = -3.52204564228463e-09;
			parameters_array->sensor_bottomMiddle[15][0] = 3.68817385064927e-06;
			parameters_array->sensor_bottomMiddle[16][0] = 3.64964149839857e-14;
			parameters_array->sensor_bottomMiddle[17][0] = 4.18956411871844e-09;
			parameters_array->sensor_bottomMiddle[18][0] = -5.06492278620579e-07;
			parameters_array->sensor_bottomMiddle[19][0] = -0.323730194191146;

			// SensorArray 1 Middle Row - Top Sensor - Y Direction
			parameters_array->sensor_topMiddle[0][1] = -6.45009050644189e-13;
			parameters_array->sensor_topMiddle[1][1] = 8.56420116659700e-13;
			parameters_array->sensor_topMiddle[2][1] = -1.10537706365247e-12;
			parameters_array->sensor_topMiddle[3][1] = -2.62299693784769e-08;
			parameters_array->sensor_topMiddle[4][1] = -7.21992827210774e-13;
			parameters_array->sensor_topMiddle[5][1] = 6.31119071600235e-14;
			parameters_array->sensor_topMiddle[6][1] = -2.41808511731862e-09;
			parameters_array->sensor_topMiddle[7][1] = 4.92633301719305e-13;
			parameters_array->sensor_topMiddle[8][1] = 2.12110771522549e-08;
			parameters_array->sensor_topMiddle[9][1] = 0.000239924652341243;
			parameters_array->sensor_topMiddle[10][1] = 5.92922718778950e-13;
			parameters_array->sensor_topMiddle[11][1] = -9.87618832235080e-13;
			parameters_array->sensor_topMiddle[12][1] = -2.54445352985294e-08;
			parameters_array->sensor_topMiddle[13][1] = -6.33158667412956e-13;
			parameters_array->sensor_topMiddle[14][1] = -4.61289773271452e-08;
			parameters_array->sensor_topMiddle[15][1] = -0.000990013312368747;
			parameters_array->sensor_topMiddle[16][1] = 1.97110853286696e-13;
			parameters_array->sensor_topMiddle[17][1] = 1.33167991198687e-08;
			parameters_array->sensor_topMiddle[18][1] = 0.000331446507341279;
			parameters_array->sensor_topMiddle[19][1] = 2.04016205731674;
			
			// SensorArray 1 Middle Row - Middle Sensor - Y Direction
			parameters_array->sensor_middleMiddle[0][1] = 1.45377112442212e-14;
			parameters_array->sensor_middleMiddle[1][1] = 1.29403507914965e-12;
			parameters_array->sensor_middleMiddle[2][1] = 9.40368966826124e-14;
			parameters_array->sensor_middleMiddle[3][1] = -6.01823570434061e-10;
			parameters_array->sensor_middleMiddle[4][1] = 9.24808627371751e-16;
			parameters_array->sensor_middleMiddle[5][1] = -2.03447507480317e-13;
			parameters_array->sensor_middleMiddle[6][1] = -4.97699891378412e-09;
			parameters_array->sensor_middleMiddle[7][1] = -3.82340595133973e-13;
			parameters_array->sensor_middleMiddle[8][1] = -1.29627763630168e-08;
			parameters_array->sensor_middleMiddle[9][1] = -0.000103356540013733;
			parameters_array->sensor_middleMiddle[10][1] = 8.21800519823719e-13;
			parameters_array->sensor_middleMiddle[11][1] = -9.17470779684042e-14;
			parameters_array->sensor_middleMiddle[12][1] = -6.84744500585344e-09;
			parameters_array->sensor_middleMiddle[13][1] = -1.90910758349836e-13;
			parameters_array->sensor_middleMiddle[14][1] = -2.55107394637301e-08;
			parameters_array->sensor_middleMiddle[15][1] = -0.000715797349964284;
			parameters_array->sensor_middleMiddle[16][1] = 6.26731527250649e-14;
			parameters_array->sensor_middleMiddle[17][1] = 4.43934339226496e-09;
			parameters_array->sensor_middleMiddle[18][1] = 0.000115837630373123;
			parameters_array->sensor_middleMiddle[19][1] = 0.435197462873514;
			
			// SensorArray 1 Middle Row - Bottom Sensor - Y Direction
			parameters_array->sensor_bottomMiddle[0][1] = 5.34368431957729e-14;
			parameters_array->sensor_bottomMiddle[1][1] = 1.32838241905495e-12;
			parameters_array->sensor_bottomMiddle[2][1] = 1.86900901495481e-13;
			parameters_array->sensor_bottomMiddle[3][1] = 6.38376916657335e-09;
			parameters_array->sensor_bottomMiddle[4][1] = -3.09318566975874e-13;
			parameters_array->sensor_bottomMiddle[5][1] = 1.36180153563080e-13;
			parameters_array->sensor_bottomMiddle[6][1] = -2.07145721460530e-09;
			parameters_array->sensor_bottomMiddle[7][1] = -2.88667185588367e-14;
			parameters_array->sensor_bottomMiddle[8][1] = -2.51766180117673e-09;
			parameters_array->sensor_bottomMiddle[9][1] = -4.85574658632464e-05;
			parameters_array->sensor_bottomMiddle[10][1] = 3.28430152450687e-13;
			parameters_array->sensor_bottomMiddle[11][1] = 6.95953728085800e-13;
			parameters_array->sensor_bottomMiddle[12][1] = 1.18953467429566e-08;
			parameters_array->sensor_bottomMiddle[13][1] = 1.16692907623104e-14;
			parameters_array->sensor_bottomMiddle[14][1] = -2.20791177784033e-08;
			parameters_array->sensor_bottomMiddle[15][1] = -0.000726654451123241;
			parameters_array->sensor_bottomMiddle[16][1] = -6.62876746407006e-15;
			parameters_array->sensor_bottomMiddle[17][1] = 1.86997928523264e-09;
			parameters_array->sensor_bottomMiddle[18][1] = 4.33542819767401e-05;
			parameters_array->sensor_bottomMiddle[19][1] = 0.0796609498379593;

			// SensorArray 1 Middle Row - Top Sensor - Z Direction
			parameters_array->sensor_topMiddle[0][2] = -4.34059778331485e-12;
			parameters_array->sensor_topMiddle[1][2] = -8.28926662948232e-12;
			parameters_array->sensor_topMiddle[2][2] = 1.72123959911660e-12;
			parameters_array->sensor_topMiddle[3][2] = 1.47520524975115e-07;
			parameters_array->sensor_topMiddle[4][2] = -8.48978421854969e-13;
			parameters_array->sensor_topMiddle[5][2] = -5.83546950527499e-13;
			parameters_array->sensor_topMiddle[6][2] = -1.83028453210665e-08;
			parameters_array->sensor_topMiddle[7][2] = -7.82409020627138e-13;
			parameters_array->sensor_topMiddle[8][2] = -3.68553316747688e-08;
			parameters_array->sensor_topMiddle[9][2] = -0.000618934016732565;
			parameters_array->sensor_topMiddle[10][2] = -8.74315884581597e-12;
			parameters_array->sensor_topMiddle[11][2] = 3.94757509292997e-12;
			parameters_array->sensor_topMiddle[12][2] = 1.63437591830056e-07;
			parameters_array->sensor_topMiddle[13][2] = 2.72457818478633e-12;
			parameters_array->sensor_topMiddle[14][2] = 1.45721649649190e-07;
			parameters_array->sensor_topMiddle[15][2] = 0.00172149693312811;
			parameters_array->sensor_topMiddle[16][2] = 4.63093934315086e-12;
			parameters_array->sensor_topMiddle[17][2] = 3.26019049903700e-07;
			parameters_array->sensor_topMiddle[18][2] = 0.00602162243960280;
			parameters_array->sensor_topMiddle[19][2] = 33.5583928131851;
			
			// SensorArray 1 Middle Row - Middle Sensor - Z Direction
			parameters_array->sensor_middleMiddle[0][2] = 1.57273197569308e-12;
			parameters_array->sensor_middleMiddle[1][2] = -5.76873742514755e-12;
			parameters_array->sensor_middleMiddle[2][2] = 7.09536485779555e-12;
			parameters_array->sensor_middleMiddle[3][2] = 2.83459797251988e-07;
			parameters_array->sensor_middleMiddle[4][2] = 2.12785391775773e-12;
			parameters_array->sensor_middleMiddle[5][2] = 3.78923113914669e-13;
			parameters_array->sensor_middleMiddle[6][2] = 1.77970473123980e-08;
			parameters_array->sensor_middleMiddle[7][2] = 2.15056331407762e-13;
			parameters_array->sensor_middleMiddle[8][2] = -8.67389663366030e-10;
			parameters_array->sensor_middleMiddle[9][2] = -0.000111456339891880;
			parameters_array->sensor_middleMiddle[10][2] = -7.37653638819061e-12;
			parameters_array->sensor_middleMiddle[11][2] = 6.37705693528412e-12;
			parameters_array->sensor_middleMiddle[12][2] = 2.46263348365865e-07;
			parameters_array->sensor_middleMiddle[13][2] = 1.74828073823045e-12;
			parameters_array->sensor_middleMiddle[14][2] = 8.76593584912443e-08;
			parameters_array->sensor_middleMiddle[15][2] = 0.000946108187868384;
			parameters_array->sensor_middleMiddle[16][2] = 5.98155348042942e-12;
			parameters_array->sensor_middleMiddle[17][2] = 3.51778821138236e-07;
			parameters_array->sensor_middleMiddle[18][2] = 0.00521529619664764;
			parameters_array->sensor_middleMiddle[19][2] = 22.7730727715328;

			// SensorArray 1 Middle Row - Bottom Sensor - Z Direction
			parameters_array->sensor_bottomMiddle[0][2] = -4.21166029076380e-14;
			parameters_array->sensor_bottomMiddle[1][2] = -4.80466271592484e-13;
			parameters_array->sensor_bottomMiddle[2][2] = 8.80575863579533e-12;
			parameters_array->sensor_bottomMiddle[3][2] = 2.93023661046751e-07;
			parameters_array->sensor_bottomMiddle[4][2] = 2.83063706038443e-12;
			parameters_array->sensor_bottomMiddle[5][2] = -2.14993890752431e-12;
			parameters_array->sensor_bottomMiddle[6][2] = -3.26167533554450e-08;
			parameters_array->sensor_bottomMiddle[7][2] = -2.51996487506808e-12;
			parameters_array->sensor_bottomMiddle[8][2] = -9.60970850993524e-08;
			parameters_array->sensor_bottomMiddle[9][2] = -0.000815073530498954;
			parameters_array->sensor_bottomMiddle[10][2] = -7.17494693946772e-13;
			parameters_array->sensor_bottomMiddle[11][2] = 5.80378090036415e-12;
			parameters_array->sensor_bottomMiddle[12][2] = 2.45088961359385e-07;
			parameters_array->sensor_bottomMiddle[13][2] = 1.60216212782832e-12;
			parameters_array->sensor_bottomMiddle[14][2] = 7.21100594776548e-08;
			parameters_array->sensor_bottomMiddle[15][2] = 0.000701947694550010;
			parameters_array->sensor_bottomMiddle[16][2] = 5.90965560269534e-12;
			parameters_array->sensor_bottomMiddle[17][2] = 3.41166608751763e-07;
			parameters_array->sensor_bottomMiddle[18][2] = 0.00502593009743136;
			parameters_array->sensor_bottomMiddle[19][2] = 21.6372994547832;

			// SensorArray 1 Right Row - Top Sensor - X Direction
			parameters_array->sensor_topRight[0][0] = -2.43668497543815e-14;
			parameters_array->sensor_topRight[1][0] = 6.13717546611491e-16;
			parameters_array->sensor_topRight[2][0] = 1.03358843969485e-13;
			parameters_array->sensor_topRight[3][0] = -2.04636808637742e-09;
			parameters_array->sensor_topRight[4][0] = 1.73943014890202e-13;
			parameters_array->sensor_topRight[5][0] = -1.82038277977881e-14;
			parameters_array->sensor_topRight[6][0] = 4.32529251234876e-10;
			parameters_array->sensor_topRight[7][0] = -1.79793548184054e-13;
			parameters_array->sensor_topRight[8][0] = -1.50403976499442e-08;
			parameters_array->sensor_topRight[9][0] = -0.000448043189516041;
			parameters_array->sensor_topRight[10][0] = 2.08983136523989e-13;
			parameters_array->sensor_topRight[11][0] = 2.22311534408228e-13;
			parameters_array->sensor_topRight[12][0] = 2.24635967017730e-09;
			parameters_array->sensor_topRight[13][0] = 3.32681250248999e-13;
			parameters_array->sensor_topRight[14][0] = 1.62899027542700e-08;
			parameters_array->sensor_topRight[15][0] = 0.000196270588314552;
			parameters_array->sensor_topRight[16][0] = 5.30211528500676e-14;
			parameters_array->sensor_topRight[17][0] = 3.36890456603529e-09;
			parameters_array->sensor_topRight[18][0] = 0.000116789928617111;
			parameters_array->sensor_topRight[19][0] = 1.38535964610313;
			
			// SensorArray 1 Right Row - Middle Sensor - X Direction
			parameters_array->sensor_middleRight[0][0] = -1.90081466112523e-13;
			parameters_array->sensor_middleRight[1][0] = 4.04495955845589e-14;
			parameters_array->sensor_middleRight[2][0] = -2.03723295746516e-13;
			parameters_array->sensor_middleRight[3][0] = -2.31800468137932e-09;
			parameters_array->sensor_middleRight[4][0] = 3.86318506627538e-13;
			parameters_array->sensor_middleRight[5][0] = -9.54639031741575e-14;
			parameters_array->sensor_middleRight[6][0] = -1.22621346706447e-09;
			parameters_array->sensor_middleRight[7][0] = -1.85122516323814e-13;
			parameters_array->sensor_middleRight[8][0] = -1.66054636612272e-08;
			parameters_array->sensor_middleRight[9][0] = -0.000509051224854555;
			parameters_array->sensor_middleRight[10][0] = 9.42884088477775e-14;
			parameters_array->sensor_middleRight[11][0] = 1.46977758739611e-13;
			parameters_array->sensor_middleRight[12][0] = 2.20674299767647e-09;
			parameters_array->sensor_middleRight[13][0] = 8.39335963679815e-14;
			parameters_array->sensor_middleRight[14][0] = 3.88963106349803e-09;
			parameters_array->sensor_middleRight[15][0] = 4.67084495082223e-05;
			parameters_array->sensor_middleRight[16][0] = 6.90542598286528e-15;
			parameters_array->sensor_middleRight[17][0] = -4.75757960369790e-11;
			parameters_array->sensor_middleRight[18][0] = -3.63499619694511e-06;
			parameters_array->sensor_middleRight[19][0] = 0.263163436953243;
			
			// SensorArray 1 Right Row - Bottom Sensor - X Direction
			parameters_array->sensor_bottomRight[0][0] = 3.80270119375568e-13;
			parameters_array->sensor_bottomRight[1][0] = -2.92607350700572e-13;
			parameters_array->sensor_bottomRight[2][0] = -1.70735147510383e-13;
			parameters_array->sensor_bottomRight[3][0] = -2.27095279403895e-09;
			parameters_array->sensor_bottomRight[4][0] = 4.56754396587587e-13;
			parameters_array->sensor_bottomRight[5][0] = 5.59448316533098e-13;
			parameters_array->sensor_bottomRight[6][0] = 1.47942091237365e-08;
			parameters_array->sensor_bottomRight[7][0] = 2.65186820810408e-14;
			parameters_array->sensor_bottomRight[8][0] = -3.38357485715913e-09;
			parameters_array->sensor_bottomRight[9][0] = -0.000292727979558325;
			parameters_array->sensor_bottomRight[10][0] = -1.05577837990654e-13;
			parameters_array->sensor_bottomRight[11][0] = 4.70850269572787e-14;
			parameters_array->sensor_bottomRight[12][0] = 3.87553982571327e-09;
			parameters_array->sensor_bottomRight[13][0] = -2.85459708705033e-13;
			parameters_array->sensor_bottomRight[14][0] = -1.40844938701582e-08;
			parameters_array->sensor_bottomRight[15][0] = -0.000162857074598991;
			parameters_array->sensor_bottomRight[16][0] = -1.48092894675720e-13;
			parameters_array->sensor_bottomRight[17][0] = -1.03075292349942e-08;
			parameters_array->sensor_bottomRight[18][0] = -0.000291562949749085;
			parameters_array->sensor_bottomRight[19][0] = -2.22811747458834;

			// SensorArray 1 Right Row - Top Sensor - Y Direction
			parameters_array->sensor_topRight[0][1] = 1.10855967490004e-13;
			parameters_array->sensor_topRight[1][1] = 3.59180166078246e-13;
			parameters_array->sensor_topRight[2][1] = -4.36642995844398e-14;
			parameters_array->sensor_topRight[3][1] = -1.65884788455611e-09;
			parameters_array->sensor_topRight[4][1] = 1.73523767514391e-13;
			parameters_array->sensor_topRight[5][1] = 7.02150752392464e-14;
			parameters_array->sensor_topRight[6][1] = 1.36147620348589e-09;
			parameters_array->sensor_topRight[7][1] = -8.72222457257068e-15;
			parameters_array->sensor_topRight[8][1] = -3.72413505526020e-10;
			parameters_array->sensor_topRight[9][1] = -5.83739785948097e-06;
			parameters_array->sensor_topRight[10][1] = 3.31352896556555e-14;
			parameters_array->sensor_topRight[11][1] = 3.32169719460827e-14;
			parameters_array->sensor_topRight[12][1] = -2.58710291323132e-09;
			parameters_array->sensor_topRight[13][1] = -2.58670389947629e-13;
			parameters_array->sensor_topRight[14][1] = -2.03404893219443e-08;
			parameters_array->sensor_topRight[15][1] = -0.000511635514302768;
			parameters_array->sensor_topRight[16][1] = 9.61644115019498e-14;
			parameters_array->sensor_topRight[17][1] = 6.18003096063301e-09;
			parameters_array->sensor_topRight[18][1] = 0.000141905262441292;
			parameters_array->sensor_topRight[19][1] = 0.970799758392682;
			
			// SensorArray 1 Right Row - Middle Sensor - Y Direction
			parameters_array->sensor_middleRight[0][1] = 4.00066022534234e-14;
			parameters_array->sensor_middleRight[1][1] = 4.63645522083018e-13;
			parameters_array->sensor_middleRight[2][1] = 3.12316325608424e-13;
			parameters_array->sensor_middleRight[3][1] = 4.06259816007320e-09;
			parameters_array->sensor_middleRight[4][1] = -1.89123325484569e-13;
			parameters_array->sensor_middleRight[5][1] = 4.74514075236477e-13;
			parameters_array->sensor_middleRight[6][1] = 8.11948683097446e-09;
			parameters_array->sensor_middleRight[7][1] = -2.13704953077906e-13;
			parameters_array->sensor_middleRight[8][1] = -7.61037763701267e-09;
			parameters_array->sensor_middleRight[9][1] = -7.11696846222789e-05;
			parameters_array->sensor_middleRight[10][1] = 1.37900797711326e-13;
			parameters_array->sensor_middleRight[11][1] = 5.83382624155489e-13;
			parameters_array->sensor_middleRight[12][1] = 7.89057407527139e-09;
			parameters_array->sensor_middleRight[13][1] = -2.12996683059050e-13;
			parameters_array->sensor_middleRight[14][1] = -2.13378797397057e-08;
			parameters_array->sensor_middleRight[15][1] = -0.000535563319582853;
			parameters_array->sensor_middleRight[16][1] = 1.45383817206026e-13;
			parameters_array->sensor_middleRight[17][1] = 7.07858247605955e-09;
			parameters_array->sensor_middleRight[18][1] = 0.000112818636905433;
			parameters_array->sensor_middleRight[19][1] = 0.620557897571275;
			
			// SensorArray 1 Right Row - Bottom Sensor - Y Direction
			parameters_array->sensor_bottomRight[0][1] = -1.15454345771136e-13;
			parameters_array->sensor_bottomRight[1][1] = 2.26887060437289e-13;
			parameters_array->sensor_bottomRight[2][1] = 3.96170159465907e-14;
			parameters_array->sensor_bottomRight[3][1] = 5.87979052371661e-10;
			parameters_array->sensor_bottomRight[4][1] = -2.00491316324410e-13;
			parameters_array->sensor_bottomRight[5][1] = 3.58454041282622e-13;
			parameters_array->sensor_bottomRight[6][1] = 8.05943315137272e-09;
			parameters_array->sensor_bottomRight[7][1] = -9.54228366856918e-14;
			parameters_array->sensor_bottomRight[8][1] = -3.61305556292458e-09;
			parameters_array->sensor_bottomRight[9][1] = -3.38470650926924e-05;
			parameters_array->sensor_bottomRight[10][1] = -4.90030825725158e-15;
			parameters_array->sensor_bottomRight[11][1] = 8.08837369399183e-14;
			parameters_array->sensor_bottomRight[12][1] = -1.24092843075473e-09;
			parameters_array->sensor_bottomRight[13][1] = -2.12841538289245e-13;
			parameters_array->sensor_bottomRight[14][1] = -2.06735626109968e-08;
			parameters_array->sensor_bottomRight[15][1] = -0.000532931211208284;
			parameters_array->sensor_bottomRight[16][1] = 2.16231295238863e-14;
			parameters_array->sensor_bottomRight[17][1] = 2.08353609795385e-09;
			parameters_array->sensor_bottomRight[18][1] = 6.11123139956793e-05;
			parameters_array->sensor_bottomRight[19][1] = 0.425798086182633;

			// SensorArray 1 Right Row - Top Sensor - Z Direction
			parameters_array->sensor_topRight[0][2] = 1.68240875948887e-13;
			parameters_array->sensor_topRight[1][2] = -1.09198783659024e-13;
			parameters_array->sensor_topRight[2][2] = 1.80040433490446e-12;
			parameters_array->sensor_topRight[3][2] = 9.80053052767661e-08;
			parameters_array->sensor_topRight[4][2] = -5.51786738650371e-13;
			parameters_array->sensor_topRight[5][2] = -4.01657613883611e-13;
			parameters_array->sensor_topRight[6][2] = -9.92489051469349e-09;
			parameters_array->sensor_topRight[7][2] = -1.50357103846653e-13;
			parameters_array->sensor_topRight[8][2] = -1.01994917536433e-08;
			parameters_array->sensor_topRight[9][2] = -0.000213933309782119;
			parameters_array->sensor_topRight[10][2] = -7.86053371208593e-13;
			parameters_array->sensor_topRight[11][2] = -1.64713418671397e-13;
			parameters_array->sensor_topRight[12][2] = 4.95963448409192e-08;
			parameters_array->sensor_topRight[13][2] = -9.98014710276376e-13;
			parameters_array->sensor_topRight[14][2] = -5.35786372126596e-08;
			parameters_array->sensor_topRight[15][2] = -0.000753449309693780;
			parameters_array->sensor_topRight[16][2] = 3.03119063292843e-13;
			parameters_array->sensor_topRight[17][2] = 2.81315055253996e-08;
			parameters_array->sensor_topRight[18][2] = 9.53264831069041e-05;
			parameters_array->sensor_topRight[19][2] = -3.50997029964378;
			
			// SensorArray 1 Right Row - Middle Sensor - Z Direction
			parameters_array->sensor_middleRight[0][2] = -1.02952253870651e-13;
			parameters_array->sensor_middleRight[1][2] = 4.42255879999486e-13;
			parameters_array->sensor_middleRight[2][2] = 3.97624123593428e-12;
			parameters_array->sensor_middleRight[3][2] = 1.68724950150810e-07;
			parameters_array->sensor_middleRight[4][2] = 8.61944861087471e-13;
			parameters_array->sensor_middleRight[5][2] = 3.58731099563620e-13;
			parameters_array->sensor_middleRight[6][2] = 8.71631429041871e-09;
			parameters_array->sensor_middleRight[7][2] = -1.44064088763364e-13;
			parameters_array->sensor_middleRight[8][2] = -1.17904864945100e-08;
			parameters_array->sensor_middleRight[9][2] = -0.000174270572965120;
			parameters_array->sensor_middleRight[10][2] = -2.82549859834078e-13;
			parameters_array->sensor_middleRight[11][2] = 1.26835666803744e-12;
			parameters_array->sensor_middleRight[12][2] = 1.15513110231312e-07;
			parameters_array->sensor_middleRight[13][2] = -1.29894474624870e-12;
			parameters_array->sensor_middleRight[14][2] = -5.31623601769691e-08;
			parameters_array->sensor_middleRight[15][2] = -0.000568981575774752;
			parameters_array->sensor_middleRight[16][2] = 1.32966689376809e-12;
			parameters_array->sensor_middleRight[17][2] = 8.84295915374750e-08;
			parameters_array->sensor_middleRight[18][2] = 0.00103404886728369;
			parameters_array->sensor_middleRight[19][2] = 2.46348893355434;
			
			// SensorArray 1 Right Row - Bottom Sensor - Z Direction
			parameters_array->sensor_bottomRight[0][2] = 7.96527932724247e-13;
			parameters_array->sensor_bottomRight[1][2] = -1.11853442320427e-12;
			parameters_array->sensor_bottomRight[2][2] = 1.14624197162136e-12;
			parameters_array->sensor_bottomRight[3][2] = 7.90510981038764e-08;
			parameters_array->sensor_bottomRight[4][2] = 3.09269005342465e-12;
			parameters_array->sensor_bottomRight[5][2] = 3.12703927750509e-12;
			parameters_array->sensor_bottomRight[6][2] = 8.25230374115939e-08;
			parameters_array->sensor_bottomRight[7][2] = 1.79262789124560e-12;
			parameters_array->sensor_bottomRight[8][2] = 8.75185332811439e-08;
			parameters_array->sensor_bottomRight[9][2] = 0.00109865143165812;
			parameters_array->sensor_bottomRight[10][2] = -9.29066481960488e-13;
			parameters_array->sensor_bottomRight[11][2] = 7.94444185683472e-14;
			parameters_array->sensor_bottomRight[12][2] = 5.10199740656176e-08;
			parameters_array->sensor_bottomRight[13][2] = -1.64028598918562e-12;
			parameters_array->sensor_bottomRight[14][2] = -8.87360980132996e-08;
			parameters_array->sensor_bottomRight[15][2] = -0.00120582598281044;
			parameters_array->sensor_bottomRight[16][2] = 4.53474577621201e-13;
			parameters_array->sensor_bottomRight[17][2] = 2.93661901213720e-08;
			parameters_array->sensor_bottomRight[18][2] = -0.000119403883600779;
			parameters_array->sensor_bottomRight[19][2] = -6.73364038418712;
			break;
	
	case 2: ;
			// SensorArray 2 Parameters - Sensor Number 5 --------------------------------------------------------------------------------
			
			// Left Row - Top Sensor - X Direction
			parameters_array->sensor_topLeft[0][0] = -3.3654e-13;
			parameters_array->sensor_topLeft[1][0] = 6.1604e-13;
			parameters_array->sensor_topLeft[2][0] = 3.6358e-13;
			parameters_array->sensor_topLeft[3][0] = -8.0157e-09;
			parameters_array->sensor_topLeft[4][0] = -3.8624e-13;
			parameters_array->sensor_topLeft[5][0] = -1.098e-12;
			parameters_array->sensor_topLeft[6][0] = -1.4167e-08;
			parameters_array->sensor_topLeft[7][0] = -1.2404e-12;
			parameters_array->sensor_topLeft[8][0] = -5.7108e-08;
			parameters_array->sensor_topLeft[9][0] = -0.00087238;
			parameters_array->sensor_topLeft[10][0] = 1.7824e-12;
			parameters_array->sensor_topLeft[11][0] = 9.2529e-13;
			parameters_array->sensor_topLeft[12][0] = 7.1362e-09;
			parameters_array->sensor_topLeft[13][0] = 1.492e-12;
			parameters_array->sensor_topLeft[14][0] = 4.4869e-08;
			parameters_array->sensor_topLeft[15][0] = 0.00034805;
			parameters_array->sensor_topLeft[16][0] = 3.8618e-13;
			parameters_array->sensor_topLeft[17][0] = 1.6756e-08;
			parameters_array->sensor_topLeft[18][0] = 0.00033829;
			parameters_array->sensor_topLeft[19][0] = 2.4612;
			
			// Left Row - Middle Sensor - X Direction
			parameters_array->sensor_middleLeft[0][0] = -6.0068e-14;
			parameters_array->sensor_middleLeft[1][0] = 7.1668e-14;
			parameters_array->sensor_middleLeft[2][0] = -2.1854e-13;
			parameters_array->sensor_middleLeft[3][0] = -3.998e-09;
			parameters_array->sensor_middleLeft[4][0] = -3.6955e-14;
			parameters_array->sensor_middleLeft[5][0] = 1.4329e-13;
			parameters_array->sensor_middleLeft[6][0] = 2.9031e-09;
			parameters_array->sensor_middleLeft[7][0] = -4.3931e-13;
			parameters_array->sensor_middleLeft[8][0] = -2.7037e-08;
			parameters_array->sensor_middleLeft[9][0] = -0.00058807;
			parameters_array->sensor_middleLeft[10][0] = 2.4361e-13;
			parameters_array->sensor_middleLeft[11][0] = -1.9465e-13;
			parameters_array->sensor_middleLeft[12][0] = -2.6875e-09;
			parameters_array->sensor_middleLeft[13][0] = 1.5804e-14;
			parameters_array->sensor_middleLeft[14][0] = -1.5105e-09;
			parameters_array->sensor_middleLeft[15][0] = -2.6443e-05;
			parameters_array->sensor_middleLeft[16][0] = -9.8312e-14;
			parameters_array->sensor_middleLeft[17][0] = -6.1003e-09;
			parameters_array->sensor_middleLeft[18][0] = -0.00010666;
			parameters_array->sensor_middleLeft[19][0] = -0.18678;
			
			// Left Row - Bottom Sensor - X Direction
			parameters_array->sensor_bottomLeft[0][0] = 7.8197e-13;
			parameters_array->sensor_bottomLeft[1][0] = -3.7121e-13;
			parameters_array->sensor_bottomLeft[2][0] = -7.7578e-16;
			parameters_array->sensor_bottomLeft[3][0] = 4.6519e-09;
			parameters_array->sensor_bottomLeft[4][0] = 8.6011e-13;
			parameters_array->sensor_bottomLeft[5][0] = 1.1279e-13;
			parameters_array->sensor_bottomLeft[6][0] = 6.7167e-09;
			parameters_array->sensor_bottomLeft[7][0] = -7.7415e-13;
			parameters_array->sensor_bottomLeft[8][0] = -3.7369e-08;
			parameters_array->sensor_bottomLeft[9][0] = -0.00067286;
			parameters_array->sensor_bottomLeft[10][0] = -6.3676e-13;
			parameters_array->sensor_bottomLeft[11][0] = 6.0188e-14;
			parameters_array->sensor_bottomLeft[12][0] = 4.3922e-09;
			parameters_array->sensor_bottomLeft[13][0] = -4.809e-13;
			parameters_array->sensor_bottomLeft[14][0] = -1.3363e-08;
			parameters_array->sensor_bottomLeft[15][0] = -0.00010474;
			parameters_array->sensor_bottomLeft[16][0] = -1.4955e-13;
			parameters_array->sensor_bottomLeft[17][0] = -7.345e-09;
			parameters_array->sensor_bottomLeft[18][0] = -0.00016335;
			parameters_array->sensor_bottomLeft[19][0] = -0.76893;
			
			// Left Row - Top Sensor - Y Direction
			parameters_array->sensor_topLeft[0][1] = -2.1351e-13;
			parameters_array->sensor_topLeft[1][1] = 5.7772e-13;
			parameters_array->sensor_topLeft[2][1] = -1.9106e-12;
			parameters_array->sensor_topLeft[3][1] = -3.2308e-08;
			parameters_array->sensor_topLeft[4][1] = 3.1745e-13;
			parameters_array->sensor_topLeft[5][1] = -8.8881e-14;
			parameters_array->sensor_topLeft[6][1] = 1.6155e-09;
			parameters_array->sensor_topLeft[7][1] = 3.3894e-13;
			parameters_array->sensor_topLeft[8][1] = 1.5917e-08;
			parameters_array->sensor_topLeft[9][1] = 0.00019244;
			parameters_array->sensor_topLeft[10][1] = -1.1295e-12;
			parameters_array->sensor_topLeft[11][1] = -1.8218e-12;
			parameters_array->sensor_topLeft[12][1] = -4.5426e-08;
			parameters_array->sensor_topLeft[13][1] = -6.0186e-13;
			parameters_array->sensor_topLeft[14][1] = -3.839e-08;
			parameters_array->sensor_topLeft[15][1] = -0.00074844;
			parameters_array->sensor_topLeft[16][1] = 7.9606e-13;
			parameters_array->sensor_topLeft[17][1] = 3.902e-08;
			parameters_array->sensor_topLeft[18][1] = 0.00068041;
			parameters_array->sensor_topLeft[19][1] = 3.581;
			
			// Left Row - Middle Sensor - Y Direction
			parameters_array->sensor_middleLeft[0][1] = 4.2505e-13;
			parameters_array->sensor_middleLeft[1][1] = 1.0153e-13;
			parameters_array->sensor_middleLeft[2][1] = -7.6803e-13;
			parameters_array->sensor_middleLeft[3][1] = -2.3348e-08;
			parameters_array->sensor_middleLeft[4][1] = 1.4112e-13;
			parameters_array->sensor_middleLeft[5][1] = -1.0874e-13;
			parameters_array->sensor_middleLeft[6][1] = -7.813e-10;
			parameters_array->sensor_middleLeft[7][1] = -2.076e-13;
			parameters_array->sensor_middleLeft[8][1] = -5.8722e-09;
			parameters_array->sensor_middleLeft[9][1] = -2.8981e-05;
			parameters_array->sensor_middleLeft[10][1] = -3.1084e-13;
			parameters_array->sensor_middleLeft[11][1] = -1.038e-12;
			parameters_array->sensor_middleLeft[12][1] = -3.283e-08;
			parameters_array->sensor_middleLeft[13][1] = -3.4386e-13;
			parameters_array->sensor_middleLeft[14][1] = -2.3997e-08;
			parameters_array->sensor_middleLeft[15][1] = -0.00057184;
			parameters_array->sensor_middleLeft[16][1] = 6.9295e-14;
			parameters_array->sensor_middleLeft[17][1] = 5.8418e-09;
			parameters_array->sensor_middleLeft[18][1] = 0.00021431;
			parameters_array->sensor_middleLeft[19][1] = 1.4814;
			
			// Left Row - Bottom Sensor - Y Direction
			parameters_array->sensor_bottomLeft[0][1] = 8.2731e-13;
			parameters_array->sensor_bottomLeft[1][1] = 5.5088e-13;
			parameters_array->sensor_bottomLeft[2][1] = -4.1505e-13;
			parameters_array->sensor_bottomLeft[3][1] = -1.7702e-08;
			parameters_array->sensor_bottomLeft[4][1] = 9.9289e-13;
			parameters_array->sensor_bottomLeft[5][1] = 5.079e-13;
			parameters_array->sensor_bottomLeft[6][1] = 7.4927e-09;
			parameters_array->sensor_bottomLeft[7][1] = -5.7872e-13;
			parameters_array->sensor_bottomLeft[8][1] = -1.9242e-08;
			parameters_array->sensor_bottomLeft[9][1] = -0.00016144;
			parameters_array->sensor_bottomLeft[10][1] = -4.16e-14;
			parameters_array->sensor_bottomLeft[11][1] = -1.1141e-12;
			parameters_array->sensor_bottomLeft[12][1] = -3.0544e-08;
			parameters_array->sensor_bottomLeft[13][1] = -8.8814e-13;
			parameters_array->sensor_bottomLeft[14][1] = -4.2215e-08;
			parameters_array->sensor_bottomLeft[15][1] = -0.00070078;
			parameters_array->sensor_bottomLeft[16][1] = 9.1167e-14;
			parameters_array->sensor_bottomLeft[17][1] = 8.1666e-09;
			parameters_array->sensor_bottomLeft[18][1] = 0.0002326;
			parameters_array->sensor_bottomLeft[19][1] = 1.488;
			
			// Left Row - Top Sensor - Z Direction
			parameters_array->sensor_topLeft[0][2] = 2.7224e-12;
			parameters_array->sensor_topLeft[1][2] = -5.5958e-12;
			parameters_array->sensor_topLeft[2][2] = 9.2778e-12;
			parameters_array->sensor_topLeft[3][2] = 3.0986e-07;
			parameters_array->sensor_topLeft[4][2] = -2.5363e-12;
			parameters_array->sensor_topLeft[5][2] = -2.0213e-12;
			parameters_array->sensor_topLeft[6][2] = -4.2912e-08;
			parameters_array->sensor_topLeft[7][2] = -2.6257e-12;
			parameters_array->sensor_topLeft[8][2] = -1.0312e-07;
			parameters_array->sensor_topLeft[9][2] = -0.0011977;
			parameters_array->sensor_topLeft[10][2] = -1.3032e-11;
			parameters_array->sensor_topLeft[11][2] = 4.5005e-12;
			parameters_array->sensor_topLeft[12][2] = 2.1907e-07;
			parameters_array->sensor_topLeft[13][2] = -5.5463e-12;
			parameters_array->sensor_topLeft[14][2] = -1.5953e-07;
			parameters_array->sensor_topLeft[15][2] = -0.0013807;
			parameters_array->sensor_topLeft[16][2] = 8.6442e-13;
			parameters_array->sensor_topLeft[17][2] = 5.8621e-08;
			parameters_array->sensor_topLeft[18][2] = -0.00029767;
			parameters_array->sensor_topLeft[19][2] = -7.7834;
			
			// Left Row - Middle Sensor - Z Direction
			parameters_array->sensor_middleLeft[0][2] = -8.3115e-13;
			parameters_array->sensor_middleLeft[1][2] = -5.6817e-13;
			parameters_array->sensor_middleLeft[2][2] = 6.1338e-12;
			parameters_array->sensor_middleLeft[3][2] = 2.0253e-07;
			parameters_array->sensor_middleLeft[4][2] = 1.8705e-13;
			parameters_array->sensor_middleLeft[5][2] = -2.3822e-12;
			parameters_array->sensor_middleLeft[6][2] = -4.3156e-08;
			parameters_array->sensor_middleLeft[7][2] = 2.5883e-13;
			parameters_array->sensor_middleLeft[8][2] = -1.1166e-08;
			parameters_array->sensor_middleLeft[9][2] = -0.00027164;
			parameters_array->sensor_middleLeft[10][2] = -3.2929e-12;
			parameters_array->sensor_middleLeft[11][2] = 9.3982e-12;
			parameters_array->sensor_middleLeft[12][2] = 2.2857e-07;
			parameters_array->sensor_middleLeft[13][2] = -2.5981e-13;
			parameters_array->sensor_middleLeft[14][2] = 2.8851e-08;
			parameters_array->sensor_middleLeft[15][2] = 0.00038278;
			parameters_array->sensor_middleLeft[16][2] = 2.0614e-12;
			parameters_array->sensor_middleLeft[17][2] = 1.1735e-07;
			parameters_array->sensor_middleLeft[18][2] = 0.00133;
			parameters_array->sensor_middleLeft[19][2] = 3.2646;
			
			// Left Row - Bottom Sensor - Z Direction
			parameters_array->sensor_bottomLeft[0][2] = -1.7987e-12;
			parameters_array->sensor_bottomLeft[1][2] = -2.1666e-12;
			parameters_array->sensor_bottomLeft[2][2] = 8.7117e-12;
			parameters_array->sensor_bottomLeft[3][2] = 2.691e-07;
			parameters_array->sensor_bottomLeft[4][2] = 1.3946e-12;
			parameters_array->sensor_bottomLeft[5][2] = -2.4585e-12;
			parameters_array->sensor_bottomLeft[6][2] = -2.2618e-08;
			parameters_array->sensor_bottomLeft[7][2] = 2.1715e-12;
			parameters_array->sensor_bottomLeft[8][2] = 6.4464e-08;
			parameters_array->sensor_bottomLeft[9][2] = 0.00054296;
			parameters_array->sensor_bottomLeft[10][2] = -5.8062e-12;
			parameters_array->sensor_bottomLeft[11][2] = 1.225e-11;
			parameters_array->sensor_bottomLeft[12][2] = 2.9656e-07;
			parameters_array->sensor_bottomLeft[13][2] = -8.9767e-14;
			parameters_array->sensor_bottomLeft[14][2] = 7.811e-09;
			parameters_array->sensor_bottomLeft[15][2] = -6.922e-05;
			parameters_array->sensor_bottomLeft[16][2] = 3.7346e-12;
			parameters_array->sensor_bottomLeft[17][2] = 1.6516e-07;
			parameters_array->sensor_bottomLeft[18][2] = 0.0013217;
			parameters_array->sensor_bottomLeft[19][2] = 1.5238;

			// Middle Row - Top Sensor - X Direction
			parameters_array->sensor_topMiddle[0][0] = 1.4542e-14;
			parameters_array->sensor_topMiddle[1][0] = 1.7616e-13;
			parameters_array->sensor_topMiddle[2][0] = 1.2985e-13;
			parameters_array->sensor_topMiddle[3][0] = -1.3105e-08;
			parameters_array->sensor_topMiddle[4][0] = 4.6868e-13;
			parameters_array->sensor_topMiddle[5][0] = -1.0831e-13;
			parameters_array->sensor_topMiddle[6][0] = 3.2315e-11;
			parameters_array->sensor_topMiddle[7][0] = -1.085e-13;
			parameters_array->sensor_topMiddle[8][0] = -1.7895e-08;
			parameters_array->sensor_topMiddle[9][0] = -0.00060645;
			parameters_array->sensor_topMiddle[10][0] = 1.8039e-13;
			parameters_array->sensor_topMiddle[11][0] = -3.862e-13;
			parameters_array->sensor_topMiddle[12][0] = -2.0943e-08;
			parameters_array->sensor_topMiddle[13][0] = 2.895e-13;
			parameters_array->sensor_topMiddle[14][0] = 8.2119e-09;
			parameters_array->sensor_topMiddle[15][0] = 4.1202e-05;
			parameters_array->sensor_topMiddle[16][0] = 3.2678e-13;
			parameters_array->sensor_topMiddle[17][0] = 1.435e-08;
			parameters_array->sensor_topMiddle[18][0] = 0.00033588;
			parameters_array->sensor_topMiddle[19][0] = 3.141;
			
			// Middle Row - Middle Sensor - X Direction
			parameters_array->sensor_middleMiddle[0][0] = 9.0918e-15;
			parameters_array->sensor_middleMiddle[1][0] = -5.6618e-14;
			parameters_array->sensor_middleMiddle[2][0] = -4.6523e-13;
			parameters_array->sensor_middleMiddle[3][0] = -1.1194e-08;
			parameters_array->sensor_middleMiddle[4][0] = 3.546e-13;
			parameters_array->sensor_middleMiddle[5][0] = 4.08e-13;
			parameters_array->sensor_middleMiddle[6][0] = 1.003e-08;
			parameters_array->sensor_middleMiddle[7][0] = 9.3891e-13;
			parameters_array->sensor_middleMiddle[8][0] = 2.714e-08;
			parameters_array->sensor_middleMiddle[9][0] = -0.00013624;
			parameters_array->sensor_middleMiddle[10][0] = 6.6559e-14;
			parameters_array->sensor_middleMiddle[11][0] = 6.1834e-14;
			parameters_array->sensor_middleMiddle[12][0] = -9.0512e-10;
			parameters_array->sensor_middleMiddle[13][0] = 2.0388e-13;
			parameters_array->sensor_middleMiddle[14][0] = 8.0628e-09;
			parameters_array->sensor_middleMiddle[15][0] = 6.9898e-05;
			parameters_array->sensor_middleMiddle[16][0] = -7.4716e-14;
			parameters_array->sensor_middleMiddle[17][0] = -4.9519e-09;
			parameters_array->sensor_middleMiddle[18][0] = -8.2339e-05;
			parameters_array->sensor_middleMiddle[19][0] = -0.30209;
			
			// Middle Row - Bottom Sensor - X Direction
			parameters_array->sensor_bottomMiddle[0][0] = 7.7186e-13;
			parameters_array->sensor_bottomMiddle[1][0] = -8.5597e-13;
			parameters_array->sensor_bottomMiddle[2][0] = -9.3751e-13;
			parameters_array->sensor_bottomMiddle[3][0] = -9.5949e-09;
			parameters_array->sensor_bottomMiddle[4][0] = 6.9725e-13;
			parameters_array->sensor_bottomMiddle[5][0] = 4.9223e-13;
			parameters_array->sensor_bottomMiddle[6][0] = 1.4475e-08;
			parameters_array->sensor_bottomMiddle[7][0] = 1.7549e-13;
			parameters_array->sensor_bottomMiddle[8][0] = -4.0638e-09;
			parameters_array->sensor_bottomMiddle[9][0] = -0.0004795;
			parameters_array->sensor_bottomMiddle[10][0] = -2.6917e-13;
			parameters_array->sensor_bottomMiddle[11][0] = 6.6346e-13;
			parameters_array->sensor_bottomMiddle[12][0] = 1.9815e-08;
			parameters_array->sensor_bottomMiddle[13][0] = 1.1668e-13;
			parameters_array->sensor_bottomMiddle[14][0] = 7.4294e-09;
			parameters_array->sensor_bottomMiddle[15][0] = 8.4735e-05;
			parameters_array->sensor_bottomMiddle[16][0] = 1.5025e-13;
			parameters_array->sensor_bottomMiddle[17][0] = 8.9557e-09;
			parameters_array->sensor_bottomMiddle[18][0] = 8.3084e-05;
			parameters_array->sensor_bottomMiddle[19][0] = -0.093546;
			
			// Middle Row - Top Sensor - Y Direction
			parameters_array->sensor_topMiddle[0][1] = 3.3742e-14;
			parameters_array->sensor_topMiddle[1][1] = 1.1601e-12;
			parameters_array->sensor_topMiddle[2][1] = -1.0923e-12;
			parameters_array->sensor_topMiddle[3][1] = -1.323e-08;
			parameters_array->sensor_topMiddle[4][1] = 4.911e-13;
			parameters_array->sensor_topMiddle[5][1] = 6.2781e-13;
			parameters_array->sensor_topMiddle[6][1] = 1.1465e-08;
			parameters_array->sensor_topMiddle[7][1] = 4.1809e-13;
			parameters_array->sensor_topMiddle[8][1] = 1.81e-08;
			parameters_array->sensor_topMiddle[9][1] = 0.00020261;
			parameters_array->sensor_topMiddle[10][1] = 2.3256e-13;
			parameters_array->sensor_topMiddle[11][1] = -9.8691e-13;
			parameters_array->sensor_topMiddle[12][1] = -1.9165e-08;
			parameters_array->sensor_topMiddle[13][1] = -1.8865e-12;
			parameters_array->sensor_topMiddle[14][1] = -8.9896e-08;
			parameters_array->sensor_topMiddle[15][1] = -0.0013533;
			parameters_array->sensor_topMiddle[16][1] = -8.594e-13;
			parameters_array->sensor_topMiddle[17][1] = -4.3163e-08;
			parameters_array->sensor_topMiddle[18][1] = -0.00074675;
			parameters_array->sensor_topMiddle[19][1] = -4.9353;
			
			// Middle Row - Middle Sensor - Y Direction
			parameters_array->sensor_middleMiddle[0][1] = 2.0119e-13;
			parameters_array->sensor_middleMiddle[1][1] = 7.8794e-13;
			parameters_array->sensor_middleMiddle[2][1] = -4.5428e-13;
			parameters_array->sensor_middleMiddle[3][1] = -7.2556e-09;
			parameters_array->sensor_middleMiddle[4][1] = 2.0195e-13;
			parameters_array->sensor_middleMiddle[5][1] = 1.9829e-13;
			parameters_array->sensor_middleMiddle[6][1] = 2.9341e-09;
			parameters_array->sensor_middleMiddle[7][1] = -2.9958e-14;
			parameters_array->sensor_middleMiddle[8][1] = 8.8113e-10;
			parameters_array->sensor_middleMiddle[9][1] = 3.196e-05;
			parameters_array->sensor_middleMiddle[10][1] = 3.091e-13;
			parameters_array->sensor_middleMiddle[11][1] = 3.5815e-13;
			parameters_array->sensor_middleMiddle[12][1] = 5.4199e-09;
			parameters_array->sensor_middleMiddle[13][1] = 2.4513e-13;
			parameters_array->sensor_middleMiddle[14][1] = -4.1127e-09;
			parameters_array->sensor_middleMiddle[15][1] = -0.00048554;
			parameters_array->sensor_middleMiddle[16][1] = -4.3127e-13;
			parameters_array->sensor_middleMiddle[17][1] = -2.2224e-08;
			parameters_array->sensor_middleMiddle[18][1] = -0.00037796;
			parameters_array->sensor_middleMiddle[19][1] = -2.4643;
			
			// Middle Row - Bottom Sensor - Y Direction
			parameters_array->sensor_bottomMiddle[0][1] = 2.9364e-13;
			parameters_array->sensor_bottomMiddle[1][1] = 1.1026e-12;
			parameters_array->sensor_bottomMiddle[2][1] = -3.6898e-13;
			parameters_array->sensor_bottomMiddle[3][1] = -7.2282e-09;
			parameters_array->sensor_bottomMiddle[4][1] = 4.1011e-13;
			parameters_array->sensor_bottomMiddle[5][1] = 4.2921e-13;
			parameters_array->sensor_bottomMiddle[6][1] = 6.2458e-09;
			parameters_array->sensor_bottomMiddle[7][1] = -5.4906e-13;
			parameters_array->sensor_bottomMiddle[8][1] = -1.7559e-08;
			parameters_array->sensor_bottomMiddle[9][1] = -0.00014269;
			parameters_array->sensor_bottomMiddle[10][1] = 5.8558e-13;
			parameters_array->sensor_bottomMiddle[11][1] = 5.8006e-13;
			parameters_array->sensor_bottomMiddle[12][1] = 4.2472e-09;
			parameters_array->sensor_bottomMiddle[13][1] = -2.1712e-13;
			parameters_array->sensor_bottomMiddle[14][1] = -2.4832e-08;
			parameters_array->sensor_bottomMiddle[15][1] = -0.00074643;
			parameters_array->sensor_bottomMiddle[16][1] = 7.5229e-14;
			parameters_array->sensor_bottomMiddle[17][1] = 9.6192e-09;
			parameters_array->sensor_bottomMiddle[18][1] = 0.00027362;
			parameters_array->sensor_bottomMiddle[19][1] = 1.431;
			
			// Middle Row - Top Sensor - Z Direction
			parameters_array->sensor_topMiddle[0][2] = 1.2057e-12;
			parameters_array->sensor_topMiddle[1][2] = -5.1782e-13;
			parameters_array->sensor_topMiddle[2][2] = 5.7e-12;
			parameters_array->sensor_topMiddle[3][2] = 2.4912e-07;
			parameters_array->sensor_topMiddle[4][2] = -3.7341e-13;
			parameters_array->sensor_topMiddle[5][2] = -3.0215e-12;
			parameters_array->sensor_topMiddle[6][2] = -5.6807e-08;
			parameters_array->sensor_topMiddle[7][2] = -4.1355e-12;
			parameters_array->sensor_topMiddle[8][2] = -1.688e-07;
			parameters_array->sensor_topMiddle[9][2] = -0.0017701;
			parameters_array->sensor_topMiddle[10][2] = -1.3381e-12;
			parameters_array->sensor_topMiddle[11][2] = 5.0261e-12;
			parameters_array->sensor_topMiddle[12][2] = 2.4089e-07;
			parameters_array->sensor_topMiddle[13][2] = 3.7926e-12;
			parameters_array->sensor_topMiddle[14][2] = 1.4422e-07;
			parameters_array->sensor_topMiddle[15][2] = 0.0014306;
			parameters_array->sensor_topMiddle[16][2] = 4.3318e-12;
			parameters_array->sensor_topMiddle[17][2] = 2.5689e-07;
			parameters_array->sensor_topMiddle[18][2] = 0.0035516;
			parameters_array->sensor_topMiddle[19][2] = 13.585;
			
			// Middle Row - Middle Sensor - Z Direction
			parameters_array->sensor_middleMiddle[0][2] = 8.1277e-13;
			parameters_array->sensor_middleMiddle[1][2] = -4.0372e-13;
			parameters_array->sensor_middleMiddle[2][2] = 5.7087e-12;
			parameters_array->sensor_middleMiddle[3][2] = 2.3577e-07;
			parameters_array->sensor_middleMiddle[4][2] = 1.4837e-13;
			parameters_array->sensor_middleMiddle[5][2] = -9.0903e-13;
			parameters_array->sensor_middleMiddle[6][2] = -1.9015e-08;
			parameters_array->sensor_middleMiddle[7][2] = -8.9299e-13;
			parameters_array->sensor_middleMiddle[8][2] = -4.1848e-08;
			parameters_array->sensor_middleMiddle[9][2] = -0.00046429;
			parameters_array->sensor_middleMiddle[10][2] = -2.0779e-12;
			parameters_array->sensor_middleMiddle[11][2] = 3.1529e-12;
			parameters_array->sensor_middleMiddle[12][2] = 1.8465e-07;
			parameters_array->sensor_middleMiddle[13][2] = 3.3886e-12;
			parameters_array->sensor_middleMiddle[14][2] = 1.4347e-07;
			parameters_array->sensor_middleMiddle[15][2] = 0.0015501;
			parameters_array->sensor_middleMiddle[16][2] = 7.1965e-12;
			parameters_array->sensor_middleMiddle[17][2] = 4.5064e-07;
			parameters_array->sensor_middleMiddle[18][2] = 0.0079557;
			parameters_array->sensor_middleMiddle[19][2] = 43.2311;
			
			// Middle Row - Bottom Sensor - Z Direction
			parameters_array->sensor_bottomMiddle[0][2] = 9.1857e-13;
			parameters_array->sensor_bottomMiddle[1][2] = -9.9918e-13;
			parameters_array->sensor_bottomMiddle[2][2] = 6.4304e-12;
			parameters_array->sensor_bottomMiddle[3][2] = 2.4853e-07;
			parameters_array->sensor_bottomMiddle[4][2] = 3.4895e-13;
			parameters_array->sensor_bottomMiddle[5][2] = -3.2999e-12;
			parameters_array->sensor_bottomMiddle[6][2] = -5.0759e-08;
			parameters_array->sensor_bottomMiddle[7][2] = -5.339e-13;
			parameters_array->sensor_bottomMiddle[8][2] = -1.5182e-08;
			parameters_array->sensor_bottomMiddle[9][2] = -1.6583e-05;
			parameters_array->sensor_bottomMiddle[10][2] = -2.9456e-12;
			parameters_array->sensor_bottomMiddle[11][2] = 1.0694e-11;
			parameters_array->sensor_bottomMiddle[12][2] = 3.2707e-07;
			parameters_array->sensor_bottomMiddle[13][2] = 1.074e-11;
			parameters_array->sensor_bottomMiddle[14][2] = 4.0572e-07;
			parameters_array->sensor_bottomMiddle[15][2] = 0.0037579;
			parameters_array->sensor_bottomMiddle[16][2] = 8.2514e-12;
			parameters_array->sensor_bottomMiddle[17][2] = 4.7051e-07;
			parameters_array->sensor_bottomMiddle[18][2] = 0.007387;
			parameters_array->sensor_bottomMiddle[19][2] = 35.4177;
			
			// Right Row - Top Sensor - X Direction
			parameters_array->sensor_topRight[0][0] = 1.21e-13;
			parameters_array->sensor_topRight[1][0] = 1.6095e-13;
			parameters_array->sensor_topRight[2][0] = 1.0992e-13;
			parameters_array->sensor_topRight[3][0] = -2.3867e-09;
			parameters_array->sensor_topRight[4][0] = 4.1094e-13;
			parameters_array->sensor_topRight[5][0] = 4.3393e-13;
			parameters_array->sensor_topRight[6][0] = 1.2647e-08;
			parameters_array->sensor_topRight[7][0] = -1.1173e-13;
			parameters_array->sensor_topRight[8][0] = -8.1155e-09;
			parameters_array->sensor_topRight[9][0] = -0.00030878;
			parameters_array->sensor_topRight[10][0] = 3.1179e-13;
			parameters_array->sensor_topRight[11][0] = 2.7247e-13;
			parameters_array->sensor_topRight[12][0] = 4.4004e-09;
			parameters_array->sensor_topRight[13][0] = 4.0099e-13;
			parameters_array->sensor_topRight[14][0] = 2.0887e-08;
			parameters_array->sensor_topRight[15][0] = 0.0002716;
			parameters_array->sensor_topRight[16][0] = 7.2245e-14;
			parameters_array->sensor_topRight[17][0] = 5.4979e-09;
			parameters_array->sensor_topRight[18][0] = 0.00020405;
			parameters_array->sensor_topRight[19][0] = 1.9167;
			
			// Right Row - Middle Sensor - X Direction
			parameters_array->sensor_middleRight[0][0] = -1.9934e-13;
			parameters_array->sensor_middleRight[1][0] = -2.7223e-13;
			parameters_array->sensor_middleRight[2][0] = -2.0995e-13;
			parameters_array->sensor_middleRight[3][0] = -3.6907e-09;
			parameters_array->sensor_middleRight[4][0] = 7.1491e-14;
			parameters_array->sensor_middleRight[5][0] = 4.205e-13;
			parameters_array->sensor_middleRight[6][0] = 1.1738e-08;
			parameters_array->sensor_middleRight[7][0] = -1.878e-13;
			parameters_array->sensor_middleRight[8][0] = -1.3315e-08;
			parameters_array->sensor_middleRight[9][0] = -0.00040059;
			parameters_array->sensor_middleRight[10][0] = -1.6446e-13;
			parameters_array->sensor_middleRight[11][0] = -2.8917e-13;
			parameters_array->sensor_middleRight[12][0] = -6.5851e-09;
			parameters_array->sensor_middleRight[13][0] = -1.8023e-13;
			parameters_array->sensor_middleRight[14][0] = -9.4981e-09;
			parameters_array->sensor_middleRight[15][0] = -0.00011737;
			parameters_array->sensor_middleRight[16][0] = -9.9548e-14;
			parameters_array->sensor_middleRight[17][0] = -6.8385e-09;
			parameters_array->sensor_middleRight[18][0] = -0.00015646;
			parameters_array->sensor_middleRight[19][0] = -1.0232;
			
			// Right Row - Bottom Sensor - X Direction
			parameters_array->sensor_bottomRight[0][0] = -7.1071e-16;
			parameters_array->sensor_bottomRight[1][0] = -7.1388e-14;
			parameters_array->sensor_bottomRight[2][0] = -1.9277e-14;
			parameters_array->sensor_bottomRight[3][0] = 4.0829e-09;
			parameters_array->sensor_bottomRight[4][0] = 5.4959e-13;
			parameters_array->sensor_bottomRight[5][0] = 8.4372e-15;
			parameters_array->sensor_bottomRight[6][0] = 2.5161e-09;
			parameters_array->sensor_bottomRight[7][0] = -5.3587e-13;
			parameters_array->sensor_bottomRight[8][0] = -3.1284e-08;
			parameters_array->sensor_bottomRight[9][0] = -0.00064719;
			parameters_array->sensor_bottomRight[10][0] = -3.2155e-13;
			parameters_array->sensor_bottomRight[11][0] = -1.0247e-12;
			parameters_array->sensor_bottomRight[12][0] = -1.9576e-08;
			parameters_array->sensor_bottomRight[13][0] = -1.1334e-12;
			parameters_array->sensor_bottomRight[14][0] = -5.0296e-08;
			parameters_array->sensor_bottomRight[15][0] = -0.00055893;
			parameters_array->sensor_bottomRight[16][0] = -3.3555e-13;
			parameters_array->sensor_bottomRight[17][0] = -2.1683e-08;
			parameters_array->sensor_bottomRight[18][0] = -0.00049719;
			parameters_array->sensor_bottomRight[19][0] = -3.8332;
			
			// Right Row - Top Sensor - Y Direction
			parameters_array->sensor_topRight[0][1] = 1.5966e-13;
			parameters_array->sensor_topRight[1][1] = 3.8594e-13;
			parameters_array->sensor_topRight[2][1] = -6.4163e-14;
			parameters_array->sensor_topRight[3][1] = -5.6278e-10;
			parameters_array->sensor_topRight[4][1] = 3.0139e-13;
			parameters_array->sensor_topRight[5][1] = -1.5559e-13;
			parameters_array->sensor_topRight[6][1] = -1.8009e-09;
			parameters_array->sensor_topRight[7][1] = 1.2098e-13;
			parameters_array->sensor_topRight[8][1] = 4.6134e-09;
			parameters_array->sensor_topRight[9][1] = 5.4361e-05;
			parameters_array->sensor_topRight[10][1] = 3.3802e-14;
			parameters_array->sensor_topRight[11][1] = -3.8683e-14;
			parameters_array->sensor_topRight[12][1] = -4.8227e-09;
			parameters_array->sensor_topRight[13][1] = -2.3842e-13;
			parameters_array->sensor_topRight[14][1] = -1.9041e-08;
			parameters_array->sensor_topRight[15][1] = -0.00047867;
			parameters_array->sensor_topRight[16][1] = 8.5124e-14;
			parameters_array->sensor_topRight[17][1] = 5.0213e-09;
			parameters_array->sensor_topRight[18][1] = 0.00010413;
			parameters_array->sensor_topRight[19][1] = 0.41587;
			
			// Right Row - Middle Sensor - Y Direction
			parameters_array->sensor_middleRight[0][1] = -8.3032e-14;
			parameters_array->sensor_middleRight[1][1] = 1.0194e-12;
			parameters_array->sensor_middleRight[2][1] = 1.5667e-13;
			parameters_array->sensor_middleRight[3][1] = 1.3802e-09;
			parameters_array->sensor_middleRight[4][1] = -8.1018e-13;
			parameters_array->sensor_middleRight[5][1] = -6.6029e-13;
			parameters_array->sensor_middleRight[6][1] = -2.0348e-08;
			parameters_array->sensor_middleRight[7][1] = -3.5124e-13;
			parameters_array->sensor_middleRight[8][1] = -1.5476e-08;
			parameters_array->sensor_middleRight[9][1] = -0.00017337;
			parameters_array->sensor_middleRight[10][1] = 1.683e-12;
			parameters_array->sensor_middleRight[11][1] = 1.0864e-12;
			parameters_array->sensor_middleRight[12][1] = 3.3073e-08;
			parameters_array->sensor_middleRight[13][1] = 2.9774e-13;
			parameters_array->sensor_middleRight[14][1] = 1.176e-08;
			parameters_array->sensor_middleRight[15][1] = -3.9746e-05;
			parameters_array->sensor_middleRight[16][1] = 2.4823e-13;
			parameters_array->sensor_middleRight[17][1] = 1.6227e-08;
			parameters_array->sensor_middleRight[18][1] = 0.00040154;
			parameters_array->sensor_middleRight[19][1] = 2.762;
			
			// Right Row - Bottom Sensor - Y Direction
			parameters_array->sensor_bottomRight[0][1] = -4.3898e-14;
			parameters_array->sensor_bottomRight[1][1] = 4.1151e-13;
			parameters_array->sensor_bottomRight[2][1] = -1.3706e-13;
			parameters_array->sensor_bottomRight[3][1] = -4.0953e-09;
			parameters_array->sensor_bottomRight[4][1] = 3.1018e-13;
			parameters_array->sensor_bottomRight[5][1] = 6.1773e-13;
			parameters_array->sensor_bottomRight[6][1] = 1.4132e-08;
			parameters_array->sensor_bottomRight[7][1] = -2.8896e-13;
			parameters_array->sensor_bottomRight[8][1] = -8.6098e-09;
			parameters_array->sensor_bottomRight[9][1] = -4.2807e-05;
			parameters_array->sensor_bottomRight[10][1] = 5.1204e-14;
			parameters_array->sensor_bottomRight[11][1] = -4.4582e-13;
			parameters_array->sensor_bottomRight[12][1] = -1.6379e-08;
			parameters_array->sensor_bottomRight[13][1] = -4.5987e-13;
			parameters_array->sensor_bottomRight[14][1] = -3.2859e-08;
			parameters_array->sensor_bottomRight[15][1] = -0.00070892;
			parameters_array->sensor_bottomRight[16][1] = 2.6932e-13;
			parameters_array->sensor_bottomRight[17][1] = 1.789e-08;
			parameters_array->sensor_bottomRight[18][1] = 0.00040507;
			parameters_array->sensor_bottomRight[19][1] = 2.7042;
			
			// Right Row - Top Sensor - Z Direction
			parameters_array->sensor_topRight[0][2] = -2.9498e-14;
			parameters_array->sensor_topRight[1][2] = -8.7385e-14;
			parameters_array->sensor_topRight[2][2] = 1.5697e-12;
			parameters_array->sensor_topRight[3][2] = 8.7272e-08;
			parameters_array->sensor_topRight[4][2] = -1.4037e-12;
			parameters_array->sensor_topRight[5][2] = -7.3392e-13;
			parameters_array->sensor_topRight[6][2] = -2.2417e-08;
			parameters_array->sensor_topRight[7][2] = -4.0397e-13;
			parameters_array->sensor_topRight[8][2] = -2.0291e-08;
			parameters_array->sensor_topRight[9][2] = -0.00024858;
			parameters_array->sensor_topRight[10][2] = -7.4737e-13;
			parameters_array->sensor_topRight[11][2] = 6.1156e-13;
			parameters_array->sensor_topRight[12][2] = 5.6451e-08;
			parameters_array->sensor_topRight[13][2] = -5.6011e-13;
			parameters_array->sensor_topRight[14][2] = -3.5387e-08;
			parameters_array->sensor_topRight[15][2] = -0.00060485;
			parameters_array->sensor_topRight[16][2] = 5.0835e-13;
			parameters_array->sensor_topRight[17][2] = 3.9746e-08;
			parameters_array->sensor_topRight[18][2] = 0.00038409;
			parameters_array->sensor_topRight[19][2] = -1.5029;
			
			// Right Row - Middle Sensor - Z Direction
			parameters_array->sensor_middleRight[0][2] = 9.1719e-13;
			parameters_array->sensor_middleRight[1][2] = -4.2162e-12;
			parameters_array->sensor_middleRight[2][2] = 1.0315e-12;
			parameters_array->sensor_middleRight[3][2] = 8.3965e-08;
			parameters_array->sensor_middleRight[4][2] = 2.5743e-12;
			parameters_array->sensor_middleRight[5][2] = -4.4024e-13;
			parameters_array->sensor_middleRight[6][2] = 1.4915e-08;
			parameters_array->sensor_middleRight[7][2] = -2.4007e-13;
			parameters_array->sensor_middleRight[8][2] = -1.2519e-08;
			parameters_array->sensor_middleRight[9][2] = -9.2642e-05;
			parameters_array->sensor_middleRight[10][2] = -6.9661e-12;
			parameters_array->sensor_middleRight[11][2] = 4.2166e-13;
			parameters_array->sensor_middleRight[12][2] = 1.7218e-08;
			parameters_array->sensor_middleRight[13][2] = 2.7001e-14;
			parameters_array->sensor_middleRight[14][2] = 9.6571e-09;
			parameters_array->sensor_middleRight[15][2] = -8.7786e-05;
			parameters_array->sensor_middleRight[16][2] = 9.4342e-13;
			parameters_array->sensor_middleRight[17][2] = 8.3454e-08;
			parameters_array->sensor_middleRight[18][2] = 0.0014832;
			parameters_array->sensor_middleRight[19][2] = 6.6715;
			
			// Right Row - Bottom Sensor - Z Direction
			parameters_array->sensor_bottomRight[0][2] = 3.8803e-13;
			parameters_array->sensor_bottomRight[1][2] = -1.9032e-12;
			parameters_array->sensor_bottomRight[2][2] = 9.7867e-16;
			parameters_array->sensor_bottomRight[3][2] = 6.7602e-08;
			parameters_array->sensor_bottomRight[4][2] = 2.6792e-12;
			parameters_array->sensor_bottomRight[5][2] = 4.5511e-12;
			parameters_array->sensor_bottomRight[6][2] = 1.0755e-07;
			parameters_array->sensor_bottomRight[7][2] = 4.1053e-12;
			parameters_array->sensor_bottomRight[8][2] = 1.8347e-07;
			parameters_array->sensor_bottomRight[9][2] = 0.0020743;
			parameters_array->sensor_bottomRight[10][2] = -4.1528e-12;
			parameters_array->sensor_bottomRight[11][2] = -5.9881e-12;
			parameters_array->sensor_bottomRight[12][2] = -6.6743e-08;
			parameters_array->sensor_bottomRight[13][2] = -5.9171e-12;
			parameters_array->sensor_bottomRight[14][2] = -2.7085e-07;
			parameters_array->sensor_bottomRight[15][2] = -0.003162;
			parameters_array->sensor_bottomRight[16][2] = -2.3295e-12;
			parameters_array->sensor_bottomRight[17][2] = -1.4122e-07;
			parameters_array->sensor_bottomRight[18][2] = -0.0036344;
			parameters_array->sensor_bottomRight[19][2] = -30.4994;

			break;
			}
};