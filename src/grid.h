#ifndef CR_GRID_H
#define CR_GRID_H

#include <memory>

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
	
	T& at( unsigned int Y, unsigned int X )
	{
		return data[ this->x() * Y + X ];
	}

private:
	T* data;
};

}

#endif
