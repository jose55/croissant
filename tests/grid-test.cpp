#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Point_Test
#include <boost/test/unit_test.hpp>
#include <string>

#include "../src/grid.h"
#include "../src/sub_grid.h"

struct Grids
{
	Grids()
	: a( 10, 20 ),  b( 100, 100 )
	{
		for( unsigned int y = 0; y < a.y(); y++ )
		for( unsigned int x = 0; x < a.x(); x++ )
			a(y,x) = y * x;
		
		for( unsigned int y = 0; y < b.y(); y++ )
		for( unsigned int x = 0; x < b.x(); x++ )
			b(y,x) = std::to_string(y) + " " + std::to_string(x);
	}
	
	cr::Grid<int> a;
	cr::Grid<std::string> b;
};

BOOST_FIXTURE_TEST_SUITE(Grid, Grids);

BOOST_AUTO_TEST_CASE(construction)
{
	BOOST_REQUIRE( a.y() == 10 );
	BOOST_REQUIRE( a.x() == 20 );
	BOOST_REQUIRE( b.y() == 100 );
	BOOST_REQUIRE( b.x() == 100 );
}

BOOST_AUTO_TEST_CASE(boundaries)
{
	BOOST_CHECK_THROW( a(0,20), std::out_of_range);
	BOOST_CHECK_THROW( a(0,-1), std::out_of_range);
	BOOST_CHECK_THROW( a(-1,19), std::out_of_range);
	BOOST_CHECK_THROW( a(10,19), std::out_of_range);
	
	b(10,10);
	b(0 ,99);
	b(10,99);
	b(0,10);
}

BOOST_AUTO_TEST_CASE(access)
{
	BOOST_REQUIRE( a(1,1) == 1 );
	BOOST_REQUIRE( a(0,9) == 0 );
	BOOST_REQUIRE( a(2,3) == 6 );
	BOOST_REQUIRE( a(5,5) == 25 );
	
	BOOST_REQUIRE( b(10,10) == "10 10" );
	BOOST_REQUIRE( b(99,10) == "99 10" );
	BOOST_REQUIRE( b(0,0) == "0 0" );
	BOOST_REQUIRE( b(5,1) == "5 1" );
}

BOOST_AUTO_TEST_CASE(constness)
{
	const auto& A = a;	
	A(5,5);
}

BOOST_AUTO_TEST_CASE(destruction)
{
	cr::Grid<int> g(10,10);
	
	auto b = new cr::Grid<std::string>( 100, 100 );
	delete b;
}

BOOST_AUTO_TEST_SUITE_END();
