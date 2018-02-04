#include "SevenSegmentDisplay.h"
#include <assert.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
CSevenSegmentDisplay::CSevenSegmentDisplay( const int pinSCLK, const int pinRCLE, const int pinDIO ) :
	m_impl( pinSCLK, pinRCLE, pinDIO )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegmentDisplay::DrawInteger( const int value )
{
	if( value < 0 || value > 9999 )
	{
		m_impl.DrawStroke();
		return;
	}

	byte digit[4];
	int val = value;
	int divider = 1000;
	for( byte i = 0; i < 4; ++i )
	{
		digit[i] = val / divider;
		val = val - digit[i] * divider;
		divider /= 10;
	}

	// Remove leading zero
	for( byte i = 0; i < 3; ++i )
		if( 0 == digit[i] )
			digit[i] = CSevenSegDisp3461BS::EMPTY;
		else
			break;

	m_impl.DrawDigits( digit[0], digit[1], digit[2], digit[3] );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegmentDisplay::DrawFloat( const float value, const byte digitsAfterDecimalPoint )
{
	assert( digitsAfterDecimalPoint <= 4 );

	const float multiplier = pow( 10, digitsAfterDecimalPoint );
	const int intValue = static_cast< int >( value * multiplier );
	DrawInteger( intValue );
	if( digitsAfterDecimalPoint > 0 )
	{
		bool bHasPoint[4] = { false, false, false, false };
		bHasPoint[3 - digitsAfterDecimalPoint] = true;
		m_impl.DrawDots( bHasPoint[0], bHasPoint[1], bHasPoint[2], bHasPoint[3] );
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegmentDisplay::Tick()
{
	m_impl.Tick();
}
////////////////////////////////////////////////////////////////////////////////////////////////////