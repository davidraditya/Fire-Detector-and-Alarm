/*

HOW TO:
setup(); // setup the pwm on pin GPA12, GPA13, GPA14, and GPA15
setservo(12, 50); // setservo on pin GPA12 as 50 degree

*/

void setup(void)
{
	SYSCLK->APBCLK.PWM01_EN = 1;
	SYSCLK->APBCLK.PWM23_EN = 1;
	SYSCLK->APBCLK.PWM45_EN = 1;
	SYSCLK->APBCLK.PWM67_EN = 1;
	SYS->IPRSTC2.PWM03_RST = 1;
	SYS->IPRSTC2.PWM03_RST = 0;
	SYS->IPRSTC2.PWM47_RST = 1;
	SYS->IPRSTC2.PWM47_RST = 0;
	SYS->GPAMFP.PWM0_AD13 = 1;
	SYS->GPAMFP.PWM1_AD14 = 1;
	SYS->GPAMFP.PWM2_AD15 = 1;
	SYS->GPAMFP.PWM3_I2SMCLK = 1;
	SYSCLK->CLKSEL1.PWM01_S = 2;
	SYSCLK->CLKSEL1.PWM23_S = 2;
	SYSCLK->CLKSEL2.PWM45_S = 2;
	SYSCLK->CLKSEL2.PWM67_S = 2;
	PWMA->PCR.CH0MOD = 1;
	PWMA->PCR.CH0INV = 0;
	PWMA->PCR.CH1MOD = 1;
	PWMA->PCR.CH1INV = 0;
	PWMA->PCR.CH2MOD = 1;
	PWMA->PCR.CH2INV = 0;
	PWMA->PCR.CH3MOD = 1;
	PWMA->PCR.CH3INV = 0;
	PWMA->PPR.CP01 = 255;
	PWMA->PPR.CP23 = 255;
	PWMA->CSR.CSR0 = 2;
	PWMA->CSR.CSR1 = 2;
	PWMA->CSR.CSR2 = 2;
	PWMA->CSR.CSR3 = 2;
}
uint8_t setservo(uint8_t pin, float val)
{
	if(val>180) val=180;
	float dt=SystemCoreClock/50/256/8;
	float deg=(val-0)*(12-3)/(180-0)+3;
	float cnr=dt-1;
	float cmr=dt*deg/100-1;
	switch(pin)
	{
		case 12:
			PWMA->CNR0 = cnr;
			PWMA->CMR0 = cmr;
			PWMA->CAPENR = 0;
			PWMA->POE.PWM0 = 1;
			PWMA->PCR.CH0EN = 1;
			break;
		case 13:
			PWMA->CNR1 = cnr;
			PWMA->CMR1 = cmr;
			PWMA->CAPENR = 0;
			PWMA->POE.PWM1 = 1;
			PWMA->PCR.CH1EN = 1;
			break;
		case 14:
			PWMA->CNR2 = cnr;
			PWMA->CMR2 = cmr;
			PWMA->CAPENR = 0;
			PWMA->POE.PWM2 = 1;
			PWMA->PCR.CH2EN = 1;
			break;
		case 15:
			PWMA->CNR3 = cnr;
			PWMA->CMR3 = cmr;
			PWMA->CAPENR = 0;
			PWMA->POE.PWM3 = 1;
			PWMA->PCR.CH3EN = 1;
			break;
	}
	return 0;
}