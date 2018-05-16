#pragma once

#include <QObject>
#include "gw2_agent.h"
#include "gw2_combatevent.h"
#include "gw2_skill.h"
#include "gw2_boss.h"
#include "gw2_gadget.h"
#include "gw2_player.h"
#include "gw2_character.h"
#include <string>
#include <QMap>
#include <iostream>

class GW2_CombatData : public QObject
{
	Q_OBJECT

public:
	GW2_CombatData(QObject *parent);
	~GW2_CombatData();

	//INITIAL LIST DATA MANAGEMENT
	void add_agent(GW2_Agent* agent_data);
	void add_skill(GW2_Skill* skill_data);
	void add_combatevent(GW2_CombatEvent* combatevent_data);

	void clear_agents();
	void clear_skills();
	void clear_combatevents();

	void assign_instance_id();
	void assign_master_agent();

	// INITIAL MAP DATA MANAGEMENT
	void map_add_agent(GW2_Agent* agent_data);
	void clear_agent_map();
	void map_assign_instance_id();
	void map_assign_master_agent();
	void map_assign_cbt_event();

	//FURTHER LIST DATA PARTITIONING
	void split_gadgets();
	//void split_boss();  Maybe useful?
	void split_characters();
	void split_players();


	//FURTHER MAP DATA PARTITIONING
	void map_split_gadgets();
	//void split_boss();  Maybe useful?
	void map_split_characters();
	void map_split_players();
		
	//SETTER
	void set_build_version(std::string version_str);
	void set_pov(std::string pov_str);
	void set_log_start(std::string start_time);
	void set_log_end(std::string end_time);
	void set_boss_id(uint16_t id);

	//GETTER
	std::string get_build_version();
	std::string get_pov();
	std::string get_log_start();
	std::string get_log_end();
	uint16_t get_boss_id();
	uint16_t get_upper_bytes(uint32_t number);
	uint16_t get_lower_bytes(uint32_t number);

private:
	std::string build_version;
	std::string pov = "N/A";
	std::string log_start = "yyyy-MM-dd HH:mm:ss z";
	std::string log_end = "yyyy-MM-dd HH:mm:ss z";
	uint16_t boss_id;
	
	QList<GW2_Agent*> agent_list;
	QList<GW2_Skill*> skill_list;
	QList<GW2_CombatEvent*> combatevent_list;
	
	//TODO: Rewrite to use QMap instead of lists for faster and easier access to agents via addr and src_agent/dst_agent
	QMap<uint64_t, GW2_Agent*> agent_map;
	QMap<uint64_t, GW2_Player*> player_map;

	//QList<GW2_Gadget> gadget_list;
	//QList<GW2_Character> character_list;
	//QList<GW2_Player> player_list;
	//GW2_Boss boss;

};
