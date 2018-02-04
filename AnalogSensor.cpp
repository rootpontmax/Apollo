#include "AnalogSensor.h"
#include "Arduino.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
CAnalogSensor::CAnalogSensor( const int pin ) :
	m_pin( pin )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
float CAnalogSensor::GetVoltage() const
{
	const float R1 = 30000.0f;
	const float R2 = 7500.0f;

	const int readValue = analogRead( m_pin );
   	const float readVoltage = ( static_cast< float >( readValue ) * 5.0f ) / 1023.0f;
   	const float voltage = readVoltage / R2 * ( R1 + R2 );
   	return voltage;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
float CAnalogSensor::GetCurrent() const
{
	const float mlVoltPerAmp = 185.0f; // use 100 for 20A Module and 66 for 30A Module
	const int rawValue = analogRead( m_pin );	
	const float normValue = static_cast< float >( rawValue ) / 1023.0f;
	const float voltage = normValue * 5000.0f;	// Get mV
	const float current = ( voltage - 2500.0f ) / mlVoltPerAmp;


	Serial.print( "Current: " );
	Serial.println( current );

	
	//const float current = ( static_cast< float >( readValue ) * 5.0f ) / 511.0f;
	//return current;
	//return (float)readValue;

	return 0.0f;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

