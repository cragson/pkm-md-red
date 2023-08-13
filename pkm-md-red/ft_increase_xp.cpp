#include "ft_increase_xp.hpp"

#include "globals.hpp"
#include "offsets.hpp"

void ft_increase_xp::tick()
{
	const auto current_xp = Globals::g_pAPI->read16( Offsets::first_pkm_experience );

	Globals::g_pAPI->write16( Offsets::first_pkm_experience, current_xp + 250 );

	Sleep( 250 );

	printf( "[+] Increased xp!\n" );

	this->disable();
}
