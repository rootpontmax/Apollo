
#include "SevenSegmentDisplay.h"
#include "Timer.h"

#include <DHT.h>
//#include <DHT_U.h>

static const int pinSCLK = 7;
static const int pinRCLE = 6;
static const int pinDIO = 5;

CTimer					g_fpsTimer( 250 );
CTimer					g_tempHumTimer( 1000 );
CSevenSegmentDisplay	g_indicator( pinSCLK, pinRCLE, pinDIO );
DHT 					tempHumSensor = DHT( A0, DHT11 );

unsigned int cyclesCount;
unsigned long prevTimeMS;

////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
	Serial.begin( 9600 );
	tempHumSensor.begin();
	cyclesCount = 0;
	prevTimeMS = millis();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
	++cyclesCount;

	// Check FPS counter
	if( g_fpsTimer.IsReady() )
	{
		const unsigned int fps = cyclesCount * 4;

		Serial.print( "FPS: " );
		Serial.println( fps );

		g_indicator.DrawInteger( fps );
		cyclesCount = 0;
	}

	// Check temperature and humidity
	if( g_tempHumTimer.IsReady() )
	{
		const float humidity = tempHumSensor.readHumidity();
		const float temperature = tempHumSensor.readTemperature();

		Serial.print( "Temperature: " );
		Serial.println( temperature );

		Serial.print( "Humidity: " );
		Serial.println( humidity );
	}

	g_indicator.Tick();
}
////////////////////////////////////////////////////////////////////////////////////////////////////