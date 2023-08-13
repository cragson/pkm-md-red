#pragma once
#include <cstdint>

namespace Offsets
{
	inline constexpr auto first_pkm_current_health = 0x200419E;
	inline constexpr auto first_pkm_max_health = 0x20041A0;
	inline constexpr auto first_pkm_experience = 0x20041A8;
	inline constexpr auto first_pkm_attack_1_count = 0x20042AC;
	inline constexpr auto first_pkm_attack_2_count = 0x20042B4;
	inline constexpr auto first_pkm_attack_3_count = 0x20042BC;
	inline constexpr auto first_pkm_attack_4_count = 0x0;

	inline constexpr auto second_pkm_current_health = 0x20043A6;
	inline constexpr auto second_pkm_max_health = 0x20043A8;
}