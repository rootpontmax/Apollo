////////////////////////////////////////////////////////////////////////////////////////////////////
// Class for 4-digits seven segment display 3461BS.												  //
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SEVEN_SEG_DISP_3461BS_H
#define SEVEN_SEG_DISP_3461BS_H

#include "Arduino.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
class CSevenSegDisp3461BS
{
public:
	CSevenSegDisp3461BS( const int pinSCLK, const int pinRCLE, const int pinDIO );

	static const byte EMPTY = 255;

	void	Clear();
	void	DrawErr();
	void	DrawStroke();
	void	DrawDigits( const byte a, const byte b, const byte c, const byte d );
	void	DrawDots( const bool bIsA, const bool bIsB, const bool bIsC, const bool bIsD );
	void	Tick();
	
private:

	static const byte 		MAX_MASK_COUNT = 24;
	static const byte 		MAX_REGISTER_COUNT = 4;
	

	static const byte		m_pointMask = 0b01111111;
	static const byte 		m_emptyMask = 0b11111111;

	static const byte		m_digitMask[MAX_MASK_COUNT];
	static const byte		m_registerMask[MAX_REGISTER_COUNT];
	

	const int				m_pinSCLK;
	const int 				m_pinRCLE;
	const int 				m_pinDIO;

	byte					m_digit[MAX_REGISTER_COUNT];
	bool					m_bHasPoint[MAX_REGISTER_COUNT];
};
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif