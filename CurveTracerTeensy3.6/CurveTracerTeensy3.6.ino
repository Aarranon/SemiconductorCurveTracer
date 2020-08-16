#include <SPI.h>

const int CS_Vce = 10;
const int CS_Vbb = 9;

const unsigned short maxAnalogValue = 4096;

unsigned short analogValue;

void setup()
{
	pinMode(CS_Vce, OUTPUT);
	pinMode(CS_Vbb, OUTPUT);
    SPI.begin();
	analogValue = 0;
	digitalWrite(CS_Vbb, LOW);
	SPI.transfer16(0b0111000000000000|875);
	digitalWrite(CS_Vbb, HIGH);
}


void loop()
{

			analogValue = analogValue + 1;
			if(analogValue >= maxAnalogValue)
				analogValue = 0;
			//calculate analog levels
			//send SPI
			digitalWrite(CS_Vce, LOW);
			SPI.transfer16(0b0111000000000000|analogValue);
			digitalWrite(CS_Vce, HIGH);
			
	

}

