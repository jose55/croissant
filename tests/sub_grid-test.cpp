#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Point_Test
#include <boost/test/unit_test.hpp>
#include <string>

#include "../src/grid.h"
#include "../src/sub_grid.h"

struct SubGrids
{
	SubGrids()
	: ba( 100, 100 ), a( ba, 20, 30, 40, 20 )
	{
	}
	
	cr::Grid<int> ba;
	cr::SubGrid<int> a;
};

BOOST_FIXTURE_TEST_SUITE(SubGrid, SubGrids);

BOOST_AUTO_TEST_CASE(construction)
{
	BOOST_REQUIRE( a.y() == 40 );
	BOOST_REQUIRE( a.x() == 20 );
}

BOOST_AUTO_TEST_CASE(boundaries)
{
	BOOST_CHECK_THROW( a(0,-1), std::out_of_range);
	BOOST_CHECK_THROW( a(0,20), std::out_of_range);
	BOOST_CHECK_THROW( a(-1,19), std::out_of_range);
	BOOST_CHECK_THROW( a(40,19), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(access)
{
	ba(25, 34) = 10;
	BOOST_REQUIRE( a(25 - 20, 34 - 30) == 10 );
	a(0,0) = 11;
	BOOST_REQUIRE( ba(20,30) == 11 );
	a(1,4) = 12;
	BOOST_REQUIRE( ba(21,34) == 12 );
}

BOOST_AUTO_TEST_CASE(constness)
{
	const auto& A = a;	
	A(5,5);
}

BOOST_AUTO_TEST_CASE(destruction)
{
	cr::SubGrid<int> b( ba, 10, 10, 10, 10 );
	
	auto c = new cr::SubGrid<int>(ba, 11, 11, 11, 11 );
	delete c;
}

BOOST_AUTO_TEST_SUITE_END();
