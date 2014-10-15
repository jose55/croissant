#ifndef CR_GRID_BASE_H
#define CR_GRID_BASE_H

#include <stdexcept>

namespace cr
{

template< typename T >
class SubGrid;

template< typename T >
class GridBase
{
public:
	typedef T type;
	
	GridBase( unsigned int Y, unsigned int X )
		: _y(Y), _x(X)
	{}
	
	virtual ~GridBase()= default;
	
	unsigned int x() const { return _x; }
	unsigned int y() const { return _y; }

	T& operator()( unsigned int Y, unsigned int X )
	{
		return at(Y,X);
	}
	
	const T& operator()( unsigned int Y, unsigned int X ) const
	{
		return at(Y,X);
	}
	
	virtual SubGrid<T> getSubGrid( int, int, int, int )= 0;
	
protected:
	virtual T& at( unsigned int Y,unsigned int X ) const =0;
	
private:
	const unsigned int _y;
	const unsigned int _x;
};

}

#endif
