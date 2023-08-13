#include "ft_money.hpp"

#include "offsets.hpp"
#include "globals.hpp"

void ft_money::tick()
{
	const auto current_money = Globals::g_pAPI->read16( Offsets::money );

	Globals::g_pAPI->write16( Offsets::money, current_money + 1500 );

	printf( "[+] Added money!\n" );

	Sleep( 420 );

	this->disable();
}
