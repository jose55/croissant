#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Point_Test
#include <boost/test/unit_test.hpp>
#include <string>

#include "../src/grid.h"
#include "../src/sub_grid.h"

struct SubGrids
{
	SubGrids()
	: ba( 100, 100 ),
	  a( ba, 40, 25, 20, 30 ),
	  a2( ba.getSubGrid(40, 30, 20, 30) ),
	  a3( a2.getSubGrid(30,25, 10, 10) )
	{
	}
	
	cr::Grid<int> ba;
	cr::SubGrid<int> a;
	cr::SubGrid<int> a2;
	cr::SubGrid<int> a3;
};

BOOST_FIXTURE_TEST_SUITE(SubGrid, SubGrids);

BOOST_AUTO_TEST_CASE(construction)
{
	BOOST_REQUIRE( a.y() == 40 );
	BOOST_REQUIRE( a.x() == 25 );
	
	cr::GridBase<int>& b = a;
	auto c = a.getSubGrid(10,10,10,10);
	cr::GridBase<int>& d = c;
}

BOOST_AUTO_TEST_CASE(boundaries)
{
	a(0, 24);
	BOOST_CHECK_THROW( a(0,-1), std::out_of_range);
	BOOST_CHECK_THROW( a(0,25), std::out_of_range);
	BOOST_CHECK_THROW( a(-1,24), std::out_of_range);
	BOOST_CHECK_THROW( a(40,24), std::out_of_range);
	
	a2(0, 29);
	BOOST_CHECK_THROW( a2(0,-1), std::out_of_range);
	BOOST_CHECK_THROW( a2(0,30), std::out_of_range);
	BOOST_CHECK_THROW( a2(-1,29), std::out_of_range);
	BOOST_CHECK_THROW( a2(40,29), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(access)
{
	ba(45, 54) = 10;
	BOOST_REQUIRE( a(45 - 20, 54 - 30) == 10 );
 	BOOST_REQUIRE( a2(45 - 20, 54 - 30) == 10 );
	BOOST_REQUIRE( a3(45 - 20 - 10, 54 - 30 - 10) == 10 );
	
	a(0,0) = 11;
	BOOST_REQUIRE( ba(20,30) == 11 );
	a2(1,4) = 12;
	BOOST_REQUIRE( ba(20 + 1,30 + 4) == 12 );
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
