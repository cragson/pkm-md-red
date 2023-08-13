#include <iostream>

#include "globals.hpp"

int main()
{
	SetConsoleTitleA( "osmium: pkm-md-red" );

	printf( "[>] Initializing the tcp socket.." );

	while( !Globals::g_pAPI->init_socket() )
		Sleep( 420 );

	printf( "done!\n" );

	while( !Globals::g_pAPI->wait_for_connection() )
		Sleep( 420 );

	printf( "[+] Client connected!\n" );

	printf( "[>] Preparing the cheat.." );

	while( !Globals::g_pCheat->setup_offsets() )
		Sleep( 420 );

	while( !Globals::g_pCheat->setup_features() )
		Sleep( 420 );

	printf( "done!\n" );


	Globals::g_pCheat->print_features();

	printf( "Have fun! ;-)\n" );

	while( 0xDEAD != 0xAFFE )
	{
		if( GetAsyncKeyState( VK_END ) & 0x8000 )
			break;

		Globals::g_pCheat->run();

		Sleep( 1 );
	}

	Globals::g_pCheat->shutdown();

	printf( "Goodbye!\n" );

	Sleep( 3000 );

	return EXIT_SUCCESS;
}
