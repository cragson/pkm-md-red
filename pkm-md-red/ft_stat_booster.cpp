#include "ft_stat_booster.hpp"

#include "offsets.hpp"
#include "globals.hpp"

void ft_stat_booster::tick()
{
	Globals::g_pAPI->write8( Offsets::player_stat_attack, 242 );
	Globals::g_pAPI->write8( Offsets::player_stat_special_attack, 242 );

	Globals::g_pAPI->write8( Offsets::player_stat_defense, 242 );
	Globals::g_pAPI->write8( Offsets::player_stat_special_defense, 242 );

	Globals::g_pAPI->write16( Offsets::player_iq, 1337 );

	printf( "[+] Stat boosted the player!\n" );

	Sleep( 420 );

	this->disable();
}
