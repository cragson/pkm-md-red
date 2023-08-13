#pragma once
#include <cstdint>

namespace Offsets
{
	inline constexpr std::uintptr_t dungeon_layer = 0x2004139;
	inline constexpr std::uintptr_t dungeon_max_layer1 = 0x2006A40;
	inline constexpr std::uintptr_t dungeon_max_layer2 = 0x2006A54;
	inline constexpr std::uintptr_t dungeon_max_layer3 = 0x2006A55;
	inline constexpr std::uintptr_t dungeon_max_layer4 = 0x20209BC;

	inline constexpr std::uintptr_t money = 0x203AC80;
	inline constexpr std::uintptr_t inventory = 0x203AA20;

	inline constexpr std::uintptr_t player_current_health = 0x200419E;
	inline constexpr std::uintptr_t player_max_health = 0x20041A0;
	inline constexpr std::uintptr_t player_experience = 0x20041A8;

	inline constexpr std::uintptr_t player_attack_1_count = 0x20042AC;
	inline constexpr std::uintptr_t player_attack_2_count = 0x20042B4;
	inline constexpr std::uintptr_t player_attack_3_count = 0x20042BC;
	inline constexpr std::uintptr_t player_attack_4_count = 0x0;

	inline constexpr std::uintptr_t player_stat_attack = 0x20041A4;
	inline constexpr std::uintptr_t player_stat_special_attack = 0x20041A5;
	inline constexpr std::uintptr_t player_stat_defense = 0x20041A6;
	inline constexpr std::uintptr_t player_stat_special_defense = 0x20041A7;

	inline constexpr std::uintptr_t player_iq = 0x200419C;
	inline constexpr std::uintptr_t player_level = 0x2004199;
	inline constexpr std::uintptr_t player_hold_item_count = 0x20041F0;
	inline constexpr std::uintptr_t player_hold_item_id = 0x20041F2;

	inline constexpr std::uintptr_t partner_current_health = 0x20043A6;
	inline constexpr std::uintptr_t partner_max_health = 0x20043A8;
}