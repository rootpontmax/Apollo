#include "Houston.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
CHouston::CHouston() :
    m_fpsTimer( true ),
    m_cyclesCount( 0 ),
    m_fps( 0 )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CHouston::Init()
{
    Serial.begin( 9600 );
    m_fpsTimer.Start( 1000, true );
    m_display.Init();
    m_display.SetTextMode();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CHouston::Tick()
{
    MeasureFPS();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CHouston::MeasureFPS()
{
    if( m_fpsTimer.IsReady() )
    {
        m_fps = m_cyclesCount;
        Serial.print( "FPS: " );
        Serial.println( m_fps );
        m_cyclesCount = 0;
        //m_display.DrawInt( 5, 5, m_fps );
        //m_display.DrawInt( 0, 0, 0 );
        //m_display.DrawInt( 5, 5, 0 );
        //m_display.DrawInt( 17, 13, 0 );
        //m_display.DrawInt( 32, 15, 0 );
        for( int i = 0; i < 30; ++i )
            m_display.DrawInt( i, i, 0 );
    }

    ++m_cyclesCount;
}
////////////////////////////////////////////////////////////////////////////////////////////////////