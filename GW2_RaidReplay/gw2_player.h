#pragma once

#include "gw2_agent.h"
#include "gw2_combatevent.h"

class GW2_Player : public GW2_Agent
{
	Q_OBJECT

public:
	GW2_Player(QObject *parent);
	~GW2_Player();

private:
	std::string character_name;
	std::string account_name;
	std::string subgroup;

	QMap<uint64_t, GW2_Agent*> minions_map;
	QMap<uint64_t, GW2_CombatEvent*> incoming_events;
	QMap<uint64_t, GW2_CombatEvent*> outgoing_events;

};
