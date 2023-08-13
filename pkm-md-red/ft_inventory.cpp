#include "ft_inventory.hpp"

#include <iostream>
#include <regex>

#include "offsets.hpp"
#include "globals.hpp"
#include "structs.hpp"

void ft_inventory::tick()
{
	constexpr auto craft_item_mask = []( const uint8_t _item_id )
	{
		return 0x2 << 24 | _item_id << 16 | 0x0 << 8 | 0x1;
	};

	printf( "[>] Enter the item id: " );
	std::string user_input = {};

	std::getline( std::cin, user_input );

	constexpr auto is_imm = []( const std::string& input )
	{
		static std::regex imm_regex( "(0[xX]([a-fA-F0-9]){1,16})|(\\d+)|\\d+\\.\\d+" );

		return std::regex_match( input, imm_regex );
	};

	if( !is_imm( user_input ) )
	{
		printf( "[!] Item id must be decimal or hexadecimal!\n" );

		Sleep( 350 );

		this->disable();

		return;
	}

	const auto num_user_input = user_input.contains( "0x" )
		                            ? std::stoull( user_input, nullptr, 16 )
		                            : std::stoull( user_input, nullptr, 10 );

	if( num_user_input > 235 )
	{
		printf( "[!] Item id's must be between 0 and 235!\n" );

		Sleep( 350 );

		this->disable();

		return;
	}

	for( auto idx = 0; idx < 20; idx++ )
	{
		const uint32_t inv_item = craft_item_mask( static_cast< uint32_t >( num_user_input ) );

		Globals::g_pAPI->write32( Offsets::inventory + idx * sizeof( inventory_item ), inv_item );
	}

	printf( "[+] Filled up your bag!\n" );

	Sleep( 350 );

	this->disable();
}
