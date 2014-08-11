#ifndef CR_GRID_H
#define CR_GRID_H

#include "grid_base.h"

namespace cr
{

template<typename T>
class Grid : public GridBase<T>
{
public:
	Grid( unsigned int Y, unsigned int X )
		: GridBase<T>(Y,X), data( new T[ Y*X ] )
	{
	}
	
	~Grid()
	{
		delete[] data;
	}

protected:
	T& at( unsigned int Y, unsigned int X ) const
	{
		if( Y >= this->y() || X >= this->x() )
			throw std::out_of_range("Grid::at");
		return data[ this->x() * Y + X ];
	}

private:
	T* data;
};

}

#endif
