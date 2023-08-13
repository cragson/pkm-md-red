#include "ft_restore_health.hpp"

#include "globals.hpp"
#include "offsets.hpp"

void ft_restore_health::tick()
{
	
	const auto pkm1_health     = Globals::g_pAPI->read8( Offsets::player_current_health );
	const auto pkm1_max_health = Globals::g_pAPI->read8( Offsets::player_max_health );

	const auto pkm2_health     = Globals::g_pAPI->read8( Offsets::partner_current_health );
	const auto pkm2_max_health = Globals::g_pAPI->read8( Offsets::partner_max_health );

	if( pkm1_health < pkm1_max_health )
		Globals::g_pAPI->write8( Offsets::player_current_health, pkm1_max_health );

	if( pkm2_health < pkm2_max_health )
		Globals::g_pAPI->write8( Offsets::partner_current_health, pkm2_max_health );
		
}
