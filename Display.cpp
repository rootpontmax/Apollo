
#include "Display.h"

#define SMALL_FONT

////////////////////////////////////////////////////////////////////////////////////////////////////
// Text size == 1, display: 32x15 symbols
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef SMALL_FONT
static const uint8_t    TEXT_SIZE = 0;
static const uint8_t    LETTER_SIZE_X = 5;
static const uint8_t    LETTER_SIZE_Y = 7;
static const uint8_t    LETTER_COUNT_X = 65;
static const uint8_t    LETTER_COUNT_Y = 30;
#else
static const uint8_t    TEXT_SIZE = 1;
static const uint8_t    LETTER_SIZE_X = 11;
static const uint8_t    LETTER_SIZE_Y = 15;
static const uint8_t    LETTER_COUNT_X = 32;
static const uint8_t    LETTER_COUNT_Y = 15;
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
static const uint16_t   COLOR_BLACK = 0x0000;
static const uint16_t   COLOR_BLUE = 0x001F;
static const uint16_t   COLOR_RED = 0xF800;
static const uint16_t   COLOR_GREEN = 0x07E0;
static const uint16_t   COLOR_CYAN = 0x07FF;
static const uint16_t   COLOR_MAGENTA = 0xF81F;
static const uint16_t   COLOR_YELLOW = 0xFFE0;
static const uint16_t   COLOR_WHITE = 0xFFFF;
////////////////////////////////////////////////////////////////////////////////////////////////////
CDisplay::CDisplay() :
    m_backColor( COLOR_BLACK ),
    m_textColor( COLOR_CYAN ),
    m_critColor( COLOR_RED ),
    m_rotation( 1 )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CDisplay::Init()
{
    const int screenW = m_device.width();
    const int screenH = m_device.height();
    uint16_t id = m_device.readID();

    Serial.print("Dysplay " + String( screenW ) + "x" + String( screenH ) + " ID = 0x");
    Serial.println( id, HEX );

    if( 0x00D3 == id  || 0xD3D3 == id ) 
        id = 0x9481; // write-only shield
    if( 0xFFFF == id )
        id = 0x9341; // serial

    m_device.begin( id );
    m_device.fillScreen( m_backColor );
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CDisplay::SetTextMode()
{
    m_device.setRotation( m_rotation );
    m_device.setTextColor( m_textColor );
    m_device.setTextSize( TEXT_SIZE );

#ifdef SMALL_FONT
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000000000000000000000000000000000000" );
    m_device.println( "+--------|+--------|+--------|+--------|+--------|+--------|+---|" );
#else
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    //m_device.println( "Yaw angle:     13.0" );
    //m_device.println( "Pitch angle:  317.0" );
    //m_device.println( "Roll angle:    45.1" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    m_device.println( "00000000000000000000000000000000" );
    //m_device.println( "--------------------------------" );
    m_device.println( "00000000000000000000000000000000" );
#endif
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CDisplay::DrawInt( const uint8_t x, const uint8_t y, const int value )
{
    const uint16_t symbolPosX = x * LETTER_SIZE_X + x;
    const uint16_t symbolPosY = y * LETTER_SIZE_Y + y;
    m_device.setTextColor( m_critColor );
    m_device.setCursor( symbolPosX, symbolPosY );
    m_device.print( value );
}
////////////////////////////////////////////////////////////////////////////////////////////////////