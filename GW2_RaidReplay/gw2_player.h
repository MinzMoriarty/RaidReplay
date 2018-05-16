#pragma once

#include "gw2_agent.h"

class GW2_Player : public GW2_Agent
{
	Q_OBJECT

public:
	GW2_Player(QObject *parent);
	GW2_Player(QObject *parent, GW2_Agent* agent);
	~GW2_Player();

	char* get_character_name();
	char* get_account_name();
	char* get_subgroup();

private:
	char character_name[64];
	char account_name[64];
	char subgroup[64];

	void split_name();
};
