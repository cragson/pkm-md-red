#include "pkm_cheat.hpp"

#include "ft_dungeon_skipper.hpp"
#include "ft_increase_xp.hpp"
#include "ft_inventory.hpp"
#include "ft_money.hpp"
#include "ft_restore_ap.hpp"
#include "ft_restore_health.hpp"
#include "ft_stat_booster.hpp"
#include "globals.hpp"
#include "utils.hpp"

bool pkm_cheat::setup_offsets()
{
	return true;
}

bool pkm_cheat::setup_features()
{
	auto health = std::make_unique< ft_restore_health >();
	health->disable_drawing();
	health->set_activation_delay( 420 );
	health->set_virtual_key_code( VK_NUMPAD1 );
	health->set_print_status( true );
	health->set_name( L"Always Restore Health" );

	auto ap = std::make_unique< ft_restore_ap >();
	ap->disable_drawing();
	ap->set_activation_delay( 420 );
	ap->set_virtual_key_code( VK_NUMPAD2 );
	ap->set_print_status( true );
	ap->set_name( L"Always Restore AP" );

	auto xp = std::make_unique< ft_increase_xp >();
	xp->disable_drawing();
	xp->set_activation_delay( 420 );
	xp->set_virtual_key_code( VK_NUMPAD3 );
	xp->set_print_status( false );
	xp->set_name( L"Increase XP" );

	auto inv = std::make_unique< ft_inventory >();
	inv->disable_drawing();
	inv->set_activation_delay( 420 );
	inv->set_virtual_key_code( VK_NUMPAD4 );
	inv->set_print_status( false );
	inv->set_name( L"Give Any Item" );

	auto bst = std::make_unique< ft_stat_booster >();
	bst->disable_drawing();
	bst->set_activation_delay( 420 );
	bst->set_virtual_key_code( VK_NUMPAD5 );
	bst->set_print_status( false );
	bst->set_name( L"Stat-Booster" );

	auto money = std::make_unique< ft_money >();
	money->disable_drawing();
	money->set_activation_delay( 420 );
	money->set_virtual_key_code( VK_NUMPAD6 );
	money->set_print_status( false );
	money->set_name( L"Add money" );

	auto skp = std::make_unique< ft_dungeon_skipper >();
	skp->disable_drawing();
	skp->set_activation_delay( 420 );
	skp->set_virtual_key_code( VK_NUMPAD7 );
	skp->set_print_status( false );
	skp->set_name( L"Dungeon Skipper" );

	this->m_features.push_back( std::move( health ) );
	this->m_features.push_back( std::move( xp ) );
	this->m_features.push_back( std::move( ap ) );
	this->m_features.push_back( std::move( inv ) );
	this->m_features.push_back( std::move( bst ) );
	this->m_features.push_back( std::move( money ) );
	this->m_features.push_back( std::move( skp ) );

	return true;
}

void pkm_cheat::print_features()
{
	printf( "\n" );

	printf( "Feature-Name -> Feature-Hotkey\n" );

	for( const auto& feature : this->m_features )
		printf( "[>] %-25ws -> %s\n", feature->get_name().c_str(),
		        utils::virtual_key_as_string( feature->get_virtual_key_code() ).c_str()
		);

	printf( "\n" );
}

void pkm_cheat::print_offsets()
{
	printf( "\n" );

	const auto msg = []( const std::string& name, const std::uintptr_t value )
	{
		printf( "[>] %-35s -> 0x%08X\n", name.c_str(), value );
	};


	printf( "\n" );
}

void pkm_cheat::run()
{
	for( const auto& feature : this->m_features )
	{
		// before tick'ing the feature, check first if the state will eventually change
		if( GetAsyncKeyState( feature->get_virtual_key_code() ) & 0x8000 )
			feature->toggle();

		// let the feature tick() when active
		if( feature->is_active() )
			feature->tick();
	}
}

void pkm_cheat::shutdown()
{
	// disable every feature here
	for( const auto& feature : this->m_features )
		if( feature->is_active() )
			feature->disable();
}
