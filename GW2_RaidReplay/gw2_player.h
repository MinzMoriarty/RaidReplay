#pragma once

#include "gw2_agent.h"
#include "gw2_combatevent.h"

class GW2_Player : public GW2_Agent
{
	Q_OBJECT

public:
	GW2_Player(QObject *parent);
	GW2_Player(QObject *parent, GW2_Agent* agent);
	~GW2_Player();

private:
	char character_name[64];
	char account_name[64];
	char subgroup[64];

	void split_name();

	QMap<uint64_t, GW2_Agent*> minions_map;
	QMap<uint64_t, GW2_CombatEvent*> incoming_events;
	QMap<uint64_t, GW2_CombatEvent*> outgoing_events;

};
