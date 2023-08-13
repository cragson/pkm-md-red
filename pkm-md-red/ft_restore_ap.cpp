#include "ft_restore_ap.hpp"

#include "globals.hpp"
#include "offsets.hpp"

void ft_restore_ap::tick()
{
	if( const auto cnt = Globals::g_pAPI->read8( Offsets::first_pkm_attack_1_count ); cnt != 69 )
		Globals::g_pAPI->write8( Offsets::first_pkm_attack_1_count, 69 );

	if( const auto cnt = Globals::g_pAPI->read8( Offsets::first_pkm_attack_2_count ); cnt != 69 )
		Globals::g_pAPI->write8( Offsets::first_pkm_attack_2_count, 69 );

	if( const auto cnt = Globals::g_pAPI->read8( Offsets::first_pkm_attack_3_count ); cnt != 69 )
		Globals::g_pAPI->write8( Offsets::first_pkm_attack_3_count, 69 );

	// TODO: reverse offset for 4th attack count and add here
}
