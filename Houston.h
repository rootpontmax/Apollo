////////////////////////////////////////////////////////////////////////////////////////////////////
// Class for receiver application.                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef HOUSTON_H
#define HOUSTON_H

#include "Display.h"
#include "Timer.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class CHouston
{
public:
    CHouston();
    void Init();
    void Tick();

private:

    void    MeasureFPS();

    CDisplay    m_display;
    CTimer      m_fpsTimer;
    int         m_cyclesCount;
    int         m_fps;
};
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif