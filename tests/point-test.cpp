#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Point_Test
#include <boost/test/unit_test.hpp>

#include "../src/point.h"

struct Points
{
	Points()
	: a(4,5), b(), c(2,-1), d(-2,4)
	{
	
	}
	
	const cr::Point a;
	const cr::Point b;
	cr::Point c;
	cr::Point d;
};

BOOST_FIXTURE_TEST_SUITE(Point, Points);

BOOST_AUTO_TEST_CASE(construction)
{
	BOOST_REQUIRE( a.x() == 5 && a.y() == 4 );
	BOOST_REQUIRE( b.x() == 0 && b.y() == 0 );
	BOOST_REQUIRE( c.x() == -1 && c.y() == 2 );
	BOOST_REQUIRE( d.x() == 4 && d.y() == -2);
}

BOOST_AUTO_TEST_CASE(setting)
{
	c.set(7,8);
	BOOST_REQUIRE( c.y() == 7 && c.x() == 8 );
	c.setY( 10 );
	BOOST_REQUIRE( c.y() == 10 );
	c.setX( -2 );
	BOOST_REQUIRE( c.x() == -2 );
}

BOOST_AUTO_TEST_CASE(shifting)
{
	d.shift(2,3);
	BOOST_REQUIRE( d.y() == 0 && d.x() == 7 );
	
	d.up();
	BOOST_REQUIRE( d.y() == -1 && d.x() == 7 );
	d.left();
	BOOST_REQUIRE( d.y() == -1 && d.x() == 6 );
	d.right();
	BOOST_REQUIRE( d.y() == -1 && d.x() == 7 );
	d.down();
	BOOST_REQUIRE( d.y() == 0 && d.x() == 7 );
	
	d.up(5);
	BOOST_REQUIRE( d.y() == -5 && d.x() == 7 );
	d.left(5);
	BOOST_REQUIRE( d.y() == -5 && d.x() == 2 );
	d.right(5);
	BOOST_REQUIRE( d.y() == -5 && d.x() == 7 );
	d.down(5);
	BOOST_REQUIRE( d.y() == 0 && d.x() == 7 );
}

BOOST_AUTO_TEST_SUITE_END();
