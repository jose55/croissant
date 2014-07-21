#ifndef CR_POINT_H
#define CR_POINT_H

namespace cr
{

class Point
{
public:
	Point(int Y = 0, int X = 0);
	
	// getters
	int y() const;
	int x() const;
	
	// setters
	void setX(int);
	void setY(int);
	
	void set(int,int);
	void shift(int,int);
	
private:
	int _y;
	int _x;
};

}

#endif
