#pragma once

#include <QObject>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include "gw2_combatdata.h"

using namespace std;

class GW2_Evtc_Parser : public QObject
{
	Q_OBJECT

public:	
	GW2_Evtc_Parser(QObject *parent, GW2_CombatData* dataset);
	~GW2_Evtc_Parser();

	void parse_evtc_log();
	void parse_evtc_header();
	void parse_evtc_agents();
	void parse_evtc_skills();
	void parse_evtc_cbtevents();

	void parse_evtc_header_alt();

private:
	uint32_t fIndex;
	GW2_CombatData* dataset_addr;
};
