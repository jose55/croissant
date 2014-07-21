#ifndef CR_FLAG_H
#define CR_FLAG_H

namespace cr
{

template< typename flagT >
class Flag
{
public:
	flagT getBit( int n )
	{
	 return (flagT)1 << n;
	}
	
	Flag( flagT flag = 0 )
		: _flag(flag)
	{
	}
	
	// getters
	bool none( flagT flags )
	{
		return (_flag & flags) == 0;
	}
	
	bool any( flagT flags )
	{
		return (_flag & flags) != 0;
	}
	
	bool all( flagT flags )
	{
		return (_flag & flags) == flags;
	}
	
	// setters
	void clear()
	{
		_flag = 0;
	}
	
	void up( flagT flags )
	{
		_flag |= flags;
	}
	
	void down( flagT flags )
	{
		_flag &= ~flags;
	}
	
	void toggle( flagT flags )
	{
		_flag ^= flags;
	}
	
	
	
private:
	flagT _flag;
};

}
#endif
