/* Main.ino file generated by New Project wizard
 *
 * Created:   Tue Apr 16 2024
 * Processor: Arduino Uno
 * Compiler:  Arduino AVR (Proteus)
 */

// Peripheral Configuration Code (do not edit)
//---CONFIG_BEGIN---
#pragma GCC push_options
#pragma GCC optimize ("Os")


#pragma GCC pop_options

// Peripheral Constructors

void peripheral_setup () {
}

void peripheral_loop() {
}
//---CONFIG_END---

float temp,tempC,tempV;



#include "LiquidCrystal.h"  //lcd libary                                       
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   //LCD object Parameters: (rs, enable, d4, d5, d6, d7)

                                                                                                            


void setup () {
lcd.begin(16,2);
	pinMode(A0,INPUT);
	pinMode(11,OUTPUT);
	pinMode(13,OUTPUT);
	Serial.begin(9600);
}

void loop() {
	temp = analogRead(A0);
    tempV = temp*5000/1024;
	tempC = (tempV/10)+(-50);
	Serial.println(tempC);

	if(tempC>25){
		tone(11,5000,100);
		digitalWrite(13,HIGH);
		lcd.print("High Temperature");
		delay(1000);
		lcd.clear();
	}
	else if(tempC<25 && tempC>15){
		digitalWrite(13,LOW);
		lcd.print("Normal Temperature");
		delay(1000);
		lcd.clear();
	}
else {
		digitalWrite(13,LOW);
		lcd.print("Low Temperature");
		delay(1000);
		lcd.clear();
}
