#include "Buzzer.h"
#include "Arduino.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
CBuzzer::CBuzzer( const int pin ) :
	m_freqTimer( false ),
	m_durationTimer( false ),
	m_pin( pin ),
	m_halfPeriodUS( 0 ),
	m_bIsWorking( false ),
	m_bIsUnderPower( false )
{
	//pinMode( m_pin, OUTPUT );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CBuzzer::Play( const int freqHz, const unsigned long durationUS )
{
	Stop();

	m_bIsWorking = true;

	const unsigned long period = 1000000 / freqHz;
	m_halfPeriodUS = period / 2;

	m_freqTimer.Start( m_halfPeriodUS, true );
	m_durationTimer.Start( durationUS, false );
	m_bIsUnderPower = false;

	//analogWrite( m_pin, 200 );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CBuzzer::Stop()
{
	m_freqTimer.Stop();
	m_durationTimer.Stop();
	m_bIsUnderPower = false;
	m_bIsWorking = false;
	//digitalWrite( m_pin, m_bIsUnderPower );

	analogWrite( m_pin, 0 );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CBuzzer::Tick()
{
	if( !m_bIsWorking )
		return;

	if( m_durationTimer.IsReady() )
	{
		//Serial.println( "Buzzer finished" );
		Stop();
		return;
	}

	if( m_freqTimer.IsReady() )
	{
		m_bIsUnderPower = !m_bIsUnderPower;

		if( m_bIsUnderPower )
			digitalWrite( m_pin, HIGH );
			//analogWrite( m_pin, 127 );
		else
			digitalWrite( m_pin, LOW );
			//analogWrite( m_pin, 0 );

		//digitalWrite( m_pin, m_bIsUnderPower );
		//Serial.print( "Buzzer port: " );
		//Serial.println( m_bIsUnderPower );
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////