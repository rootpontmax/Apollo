#ifndef DISPLAY_H
#define DISPLAY_H

#include <MCUFRIEND_kbv.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
class CDisplay
{
public:
    CDisplay();
    void    Init();
    void    SetTextMode();
    void    DrawInt( const uint8_t x, const uint8_t y, const int value );
private:
    MCUFRIEND_kbv   m_device;
    const uint16_t  m_backColor;
    const uint16_t  m_textColor;
    const uint16_t  m_critColor;
    const uint8_t   m_rotation;
};
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif