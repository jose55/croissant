#ifndef CR_GRID_BASE_H
#define CR_GRID_BASE_H

namespace cr
{

template< typename T >
class GridBase
{
public:
	typedef T type;
	
	GridBase( unsigned int Y, unsigned int X )
		: _y(Y), _x(X)
	{}

	unsigned int x(){ return _x; }
	unsigned int y(){ return _y; }
	
	virtual T& at( unsigned int Y, unsigned int X )=0;
	
private:
	const unsigned int _y;
	const unsigned int _x;
};

}

#endif
