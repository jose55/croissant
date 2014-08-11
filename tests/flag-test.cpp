#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Flag_Test
#include <boost/test/unit_test.hpp>

#include "../src/flag.h"

struct Flags
{
	Flags()
	: a( 0xA0000036 ), // 1010 ... 0011 0110
	  b( 0xC000002A ), // 1100 ... 0010 1010
	  c( 0x7 ),  // 0111
	  d( 0xA )   // 1010
	{
	
	}
	
	const cr::Flag<unsigned int> a;
	const cr::Flag<unsigned int> b;
	cr::Flag<char> c;
	cr::Flag<char> d;
};

BOOST_FIXTURE_TEST_SUITE(Flag, Flags);

BOOST_AUTO_TEST_CASE(construction)
{
	BOOST_REQUIRE( a.data() == 0xA0000036 );
	BOOST_REQUIRE( c.data() == 0x7 );
	BOOST_REQUIRE( d.data() == (d.getBit(3) | decltype(d)::getBit(1)) );
}

BOOST_AUTO_TEST_CASE(checking)
{
	BOOST_REQUIRE( b.all(0xC000002A) );
	BOOST_REQUIRE( b.any(0x800DF020) );
	BOOST_REQUIRE( b.none(~0xC000002A) );
	
	BOOST_REQUIRE( c.none( 0xF0 ) );
	BOOST_REQUIRE( c.any( 0xD2 ) );
	BOOST_REQUIRE( c.all( 0x03 ) );
}

BOOST_AUTO_TEST_CASE(setting)
{
	c.up( a.data() );
	BOOST_REQUIRE( c.data() == 0x37 );
	c.toggle( b.data() );
	BOOST_REQUIRE( c.data() == 0x1D );
	c.down( d.data() );
	BOOST_REQUIRE( c.data() == 0x15 );
	c.clear();
	BOOST_REQUIRE( c.data() == 0x0);
}

BOOST_AUTO_TEST_SUITE_END();
