#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"
#include "LCD_Driver.h"
#include "DrvADC.h"
#include "Seven_Segment.h"
#include "servo.h"

void Init();
//int adc;

int efek(){
	DrvGPIO_ClrBit(E_GPC,12);
	DrvGPIO_ClrBit(E_GPB,11);
    DrvSYS_Delay(1000000);
    DrvSYS_Delay(1000000);
	DrvSYS_Delay(1000000);
	close_seven_segment();
	DrvGPIO_SetBit(E_GPC,12);
	DrvGPIO_SetBit(E_GPB,11);
	DrvSYS_Delay(1000000);
}

int main(void)
{
	Init();
	Initial_pannel();
	close_seven_segment();
	setup();
	setservo(12,0);
	while (1){
		if(DrvGPIO_GetBit(E_GPA,0)==0){
			clr_all_pannal();
			DrvGPIO_ClrBit(E_GPD,14);
			print_lcd(0," !!Kebakaran!!");
			print_lcd(1,"Lakukan Evakuasi");
			print_lcd(2,"Hubungi Pemadam");
			print_lcd(3,"  Gunakan APAR ");
			int a,b,c;
			for(c=9; c>=0; c--){
	    		show_seven_segment(0,c);
	    		efek();
			}
			setup();
			setservo(12,90);
			for(a=2; a>=0; a--){
				show_seven_segment(2,a);
				efek();
			    for(b=5; b>=0; b--){
			    	show_seven_segment(1,b);
			    	efek();
			    	for(c=9; c>=0; c--){
			    		show_seven_segment(0,c);
			    		efek();
			    	}
			    }
			}
			setup();
			setservo(12,0);
		} else {
			clr_all_pannal();
			DrvGPIO_SetBit(E_GPD,14);
			DrvGPIO_SetBit(E_GPC,12);
			DrvGPIO_SetBit(E_GPB,11);
			DrvSYS_Delay(1000000);
		}
	}
	return 0;
}
