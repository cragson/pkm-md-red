#include "ft_dungeon_skipper.hpp"

#include "offsets.hpp"
#include "globals.hpp"

void ft_dungeon_skipper::tick()
{
	const auto max_layer_level = Globals::g_pAPI->read8( Offsets::dungeon_max_layer1 );

	Globals::g_pAPI->write8( Offsets::dungeon_layer, max_layer_level - 1 );

	printf( "[+] Set to last dungeon layer!\n" );

	Sleep( 420 );

	this->disable();
}
