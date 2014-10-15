#ifndef CR_SUB_GRID_H
#define CR_SUB_GRID_H

#include "grid_base.h"

namespace cr
{

template< typename T >
class SubGrid : public GridBase<T>
{
public:
	SubGrid( GridBase<T> &referent, int Y, int X, int shifty = 0, int shiftx = 0 )
	: GridBase<T>( Y, X ), _referent(&referent), y_shift(shifty), x_shift(shiftx)
	{

	}
	
	SubGrid<T> getSubGrid( int Y, int X, int shifty, int shiftx )
	{
		// subgrid of my subgrid is my subgrid
		return SubGrid<T>(*_referent, Y, X, y_shift + shifty, x_shift + shiftx );
	}
	
protected:
	T& at( unsigned int Y, unsigned int X ) const
	{
		if( Y >= this->y() || X >= this->x() )
			throw std::out_of_range("SubGrid::at");
		return (*_referent)( y_shift + Y, x_shift + X);
	}

private:
	GridBase<T>* const _referent;
	
	int y_shift;
	int x_shift;
	
	int _y;
	int _x;
};

}

#endif
