////////////////////////////////////////////////////////////////////////////////////////////////////
// Class for mathematical average several values.												  //
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef AVERAGER_H
#define AVERAGER_H

////////////////////////////////////////////////////////////////////////////////////////////////////
template< class T, int N >
class CAverager
{
public:

	/*
	CAverager( T defaultValue );
	void	SetValue( const T value );
	T 		GetAverage() const;
	*/


	CAverager( T defaultValue ) :
		m_defaultValue( defaultValue ),
		m_count( 0 ),
		m_pos( 0 )
	{}

	void SetValue( const T value )
	{
		m_data[m_pos] = value;
		++m_pos;
		++m_count;
		m_pos %= N;
		m_count = ( m_count > N ) ? N : m_count;
	}

	T GetAverage() const
	{
		T sum = m_defaultValue;
		for( int i = 0; i < m_count; ++i )
			sum += m_data[i];
		return sum / static_cast< T >( m_count );
	}

private:

	const T m_defaultValue;
	T 		m_data[N];
	int		m_count;
	int		m_pos;
};
/*
////////////////////////////////////////////////////////////////////////////////////////////////////
template< class T, int N >
CAverager< T, N >::CAverager( T defaultValue ) :
	m_defaultValue( defaultValue ),
		m_count( 0 ),
		m_pos( 0 )
{}
////////////////////////////////////////////////////////////////////////////////////////////////////
template< class T, int N >
CAverager< T, N >::SetValue( const T value )
{
	m_data[m_pos] = value;
	++m_pos;
	++m_count;
	m_pos %= N;
	m_count = ( m_count > N ) ? N : m_count;
}
/*
////////////////////////////////////////////////////////////////////////////////////////////////////
template< class T, int N >
T CAverager< T, N >::GetAverage() const
{
	T sum = defaultValue;
	for( int i = 0; i < m_count; ++i )
		sum += m_data[i];
	return seum / static_cast< T >( m_count );
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif

