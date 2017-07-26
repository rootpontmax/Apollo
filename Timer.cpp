#include "Timer.h"
#include "Arduino.h"
#include <assert.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
CTimer::CTimer() :
	m_autoRestartDelayTimeMS( 0 ),
	m_delayTimeMS( 0 ),
	m_startTimeMS( 0 ),
	m_bIsWorking( false ),
	m_bIsAutoRestarted( false )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
CTimer::CTimer( const unsigned long autoRestartDelayTimeMS ) :
	m_autoRestartDelayTimeMS( autoRestartDelayTimeMS ),
	m_delayTimeMS( 0 ),
	m_startTimeMS( millis() ),
	m_bIsWorking( true ),
	m_bIsAutoRestarted( true )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CTimer::Start( const unsigned long timeMS )
{
	assert( !m_bIsAutoRestarted );

	m_delayTimeMS = timeMS;
	m_startTimeMS = millis();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
bool CTimer::IsReady()
{
	if( !m_bIsWorking )
		return false;

	const unsigned long thisTimeMS = millis();
	const unsigned long deltaTimeMS = thisTimeMS - m_startTimeMS;

	const unsigned long actualDelay = m_bIsAutoRestarted ? m_autoRestartDelayTimeMS : m_delayTimeMS;
	if( deltaTimeMS > actualDelay )
	{
		if( m_bIsAutoRestarted )
			m_startTimeMS = thisTimeMS;
		else
			m_bIsWorking = false;
		return true;
	}

	return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

