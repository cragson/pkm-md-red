#pragma once
#include "mgba_api.hpp"
#include "pkm_cheat.hpp"

namespace Globals
{
	inline auto g_pCheat = std::make_unique< pkm_cheat >();

	inline auto g_pAPI = std::make_unique< mgba_api >();
}