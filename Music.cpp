#include "Music.h"
#include "Arduino.h"
#include <assert.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
SMusicNote::SMusicNote( const unsigned int f, const unsigned int p ) :
	freqHz( f ),
	part( p )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
CMusic::CMusic( const int pin ) :
	m_timer( true ),
	m_pNote( nullptr ),
	m_pin( pin ),
	m_noteCount( 0 ),
	m_currentNote( 0 ),
	m_bIsPlaying( false )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CMusic::Init( SMusicNote *pNote, const int count )
{
	Serial.println( "Music::Play()" );
	m_pNote = pNote;
	m_noteCount = count;
	m_currentNote = -1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CMusic::Play()
{
	m_bIsPlaying = true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CMusic::Pause()
{
	m_bIsPlaying = false;
	noTone( m_pin );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CMusic::Tick()
{
	if( !m_bIsPlaying )
		return;

	Serial.print( "Music::Tick():" );
	Serial.println( m_currentNote );

	if( -1 == m_currentNote )
	{
		StartNextNote();
		return;
	}

	if( m_timer.IsReady() )
		StartNextNote();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CMusic::StartNextNote()
{
	++m_currentNote;

	Serial.print( "Music::StartNextNote(): " );
	Serial.print( m_currentNote );

	if( m_currentNote > m_noteCount )
	{
		Serial.println( "Music::Stop()" );
		m_currentNote = -1;
		m_bIsPlaying = false;
		noTone( m_pin );
		return;
	}

	const SMusicNote& note = m_pNote[m_currentNote];

	Serial.print( "; note.freq: " );
	Serial.print( note.freqHz );

	Serial.print( "; note.part: " );
	Serial.print( note.part );

	const unsigned long timeMS = 1000 / note.part;
	tone( m_pin, note.freqHz, timeMS );
	m_timer.Start( timeMS, false );

	Serial.print( "; timeMS: " );
	Serial.println( timeMS );
}
////////////////////////////////////////////////////////////////////////////////////////////////////

