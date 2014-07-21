#include "point.h"

namespace cr
{

Point::Point( int Y, int X )
	: _y(Y), _x(X)
{	
}

// getters
int Point::y() const
{
	return _y;
}

int Point::x() const
{
	return _x;
}

// setters
void Point::setY( int Y )
{
	_y = Y;
}

void Point::setX( int X )
{
	_x = X;
}

void Point::set( int Y, int X )
{
	_y = Y;
	_x = X;
}

void Point::shift( int DY, int DX )
{
	_y += DY;
	_x += DX;
}


} // namespace cr
