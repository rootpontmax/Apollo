//#define ONBOARD_APPLICATION

/*
#include "SevenSegmentDisplay.h"
#include "Timer.h"
#include "Buzzer.h"
#include "AnalogButtons.h"
#include "AnalogSensor.h"
#include "Averager.h"
#include "Display.h"
*/

#ifdef ONBOARD_APPLICATION
#include "Challenger.h"
#else
#include "Houston.h"
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef ONBOARD_APPLICATION
CChallenger		g_application;
#else
CHouston		g_application;
#endif

/*
CTimer							g_fpsTimer( true );
CTFTDisplayOpenSmart400x240		g_display;
int								g_cyclesCount = 0;
*/





////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
	g_application.Init();


	/*
	Serial.begin( 9600 );
	g_fpsTimer.Start( 1000, true );
	g_display.Init();
	g_display.SetTextMode();
	*/
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
	g_application.Tick();
	/*
	// Check FPS counter
	if( g_fpsTimer.IsReady() )
	{
		const unsigned int fps = g_cyclesCount;
		Serial.print( "FPS: " );
		Serial.println( fps );
		g_cyclesCount = 0;
	}

	++g_cyclesCount;
	*/

}
////////////////////////////////////////////////////////////////////////////////////////////////////