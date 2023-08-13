#pragma once
#include "osmium/Cheat/cheat.hpp"

class pkm_cheat : public cheat
{
public:

	bool setup_offsets() override;
	bool setup_features() override;

	void print_features() override;
	void print_offsets() override;
	void run() override;
	void shutdown() override;
};