#pragma once

#include <stdint.h>
#include <QObject>
#include <QMap>
#include "gw2_combatevent.h"
#include "structs.h"

class GW2_Agent : public QObject
{
	Q_OBJECT

public:
	GW2_Agent(QObject *parent);
	GW2_Agent(QObject *parent, evtc_agent agent);
	GW2_Agent(QObject *parent, uint64_t c_addr, uint32_t c_prof, uint32_t c_is_elite, int16_t c_toughness, int16_t c_concentration, int16_t c_healing, int16_t c_pad1, int16_t c_condition, int16_t c_pad2, char* c_name);
	~GW2_Agent();

	// GETTER		
	uint64_t get_addr();
	uint32_t get_prof();
	uint32_t get_is_elite();
	int16_t get_toughness();
	int16_t get_concentration();
	int16_t get_healing();
	int16_t get_pad1();
	int16_t get_condition();
	int16_t get_pad2();
	char* get_name();
	uint16_t get_instance_id();
	uint64_t get_first_aware();
	uint64_t get_last_aware();
	uint64_t get_master_addr();

	QList<GW2_Agent*> get_minion_list();
	GW2_Agent* get_minion(uint64_t id);
	
	QList<GW2_CombatEvent*> get_incoming_events();
	QList<GW2_CombatEvent*> get_outgoing_events();
	
	QList<GW2_CombatEvent*> get_incoming_events_from(uint64_t id);
	QList<GW2_CombatEvent*> get_outgoing_events_to(uint64_t id);
	
	//SETTER
	void set_instance_id(uint16_t i_id);
	void set_first_aware(uint64_t f_aw);
	void set_last_aware(uint64_t l_aw);
	void set_master_addr(uint64_t m_addr);

	void add_incoming_event(GW2_CombatEvent* event);
	void add_outgoing_event(GW2_CombatEvent* event);
	void add_minion(GW2_Agent* minion);

	//Find a better way to keep this data protected while prep and identification are not finished
	QMap<uint64_t, GW2_Agent*> minion_map;
	QMap<uint64_t, GW2_CombatEvent*> incoming_events;
	QMap<uint64_t, GW2_CombatEvent*> outgoing_events;

protected:
	//Filled with struct data
	uint64_t addr;
	uint32_t prof;
	uint32_t is_elite;
	int16_t toughness;
	int16_t concentration;
	int16_t healing;
	int16_t pad1;
	int16_t condition;
	int16_t pad2;
	char name[64];
	
	//Initialize in constructor, modify in first analysis pass
	uint16_t instance_id;
	uint64_t first_aware;
	uint64_t last_aware;
	uint64_t master_addr;


};
