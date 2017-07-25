#include "SevenSegDisp3461BS.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
const byte CSevenSegDisp3461BS::m_digitMask[MAX_MASK_COUNT] =
{ 		
	0b11000000, // 0
	0b11111001, // 1
	0b10100100, // 2
	0b10110000, // 3
	0b10011001, // 4
	0b10010010, // 5
	0b10000010, // 6
	0b11111000, // 7
	0b10000000, // 8
	0b10010000, // 9 

	0b10001000, // A // 10
	0b11000110, // C // 11
	0b10000110, // E // 12
	0b10001110, // F // 13
	0b11000010, // G // 14
	0b10001001, // H // 15
	0b11110001, // J // 16
	0b11000111, // L // 17
	0b10100011, // o // 18
	0b10001100, // P // 19

	0b10101111, // r // 20
	0b10111111, // - // 21
	0b11110111, // _ // 22
	0b10011100, // ° // 23
};
////////////////////////////////////////////////////////////////////////////////////////////////////
const byte CSevenSegDisp3461BS::m_registerMask[MAX_REGISTER_COUNT] =
{
	0b00001000,  
	0b00000100,  
	0b00000010,  
	0b00000001 
};
////////////////////////////////////////////////////////////////////////////////////////////////////
CSevenSegDisp3461BS::CSevenSegDisp3461BS( const int pinSCLK, const int pinRCLE, const int pinDIO ) :
	m_pinSCLK( pinSCLK ),
	m_pinRCLE( pinRCLE ),
	m_pinDIO( pinDIO )
{
	Clear();

	pinMode( m_pinSCLK, OUTPUT );
  	pinMode( m_pinRCLE, OUTPUT );
  	pinMode( m_pinDIO, OUTPUT );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegDisp3461BS::Clear()
{
	for( byte i = 0; i < MAX_REGISTER_COUNT; ++i )
	{
		m_digit[i] = EMPTY;
		m_bHasPoint[i] = false;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegDisp3461BS::DrawErr()
{
	m_digit[0] = 12;
	m_digit[1] = 20;
	m_digit[2] = 20;
	m_digit[3] = EMPTY;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegDisp3461BS::DrawStroke()
{
	m_digit[0] = 21;
	m_digit[1] = 21;
	m_digit[2] = 21;
	m_digit[3] = 21;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegDisp3461BS::DrawDigits( const byte a, const byte b, const byte c, const byte d )
{
	m_digit[0] = a;
	m_digit[1] = b;
	m_digit[2] = c;
	m_digit[3] = d;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegDisp3461BS::DrawDots( const bool bIsA, const bool bIsB, const bool bIsC, const bool bIsD )
{
	m_bHasPoint[0] = bIsA;
	m_bHasPoint[1] = bIsB;
	m_bHasPoint[2] = bIsC;
	m_bHasPoint[3] = bIsD;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSevenSegDisp3461BS::Tick()
{
	for( byte i = 0; i < MAX_REGISTER_COUNT; ++i )
	{
		const byte id = m_digit[i];
		const byte mask =  ( id < MAX_MASK_COUNT ) ? m_digitMask[id] : m_emptyMask;
		const byte finalMask = ( m_bHasPoint[i] ) ? mask & m_pointMask : mask;

		digitalWrite( m_pinRCLE, LOW );
		shiftOut( m_pinDIO, m_pinSCLK, MSBFIRST, finalMask );
		shiftOut( m_pinDIO, m_pinSCLK, MSBFIRST, m_registerMask[i] );
    	digitalWrite( m_pinRCLE, HIGH );
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////