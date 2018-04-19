#include "gw2_combatdata.h"

GW2_CombatData::GW2_CombatData(QObject *parent)
	: QObject(parent)
{
	agent_list = new QList<GW2_Agent*>;
	skill_list = new QList<GW2_Skill*>;
	combatevent_list = new QList<GW2_CombatEvent*>;	
}

GW2_CombatData::~GW2_CombatData()
{
	clear_agents();
	clear_skills();
	clear_combatevents();		
	delete agent_list;
	delete skill_list;
	delete combatevent_list;
}

//
//LIST MANAGEMENT
//

void GW2_CombatData::add_agent(GW2_Agent* agent_data)
{	
	agent_list->append(agent_data);
	map_add_agent(agent_data);

	//Debugging
	/*
	using namespace std;
	cout << endl;
	cout << "NAME: ";	
	cout.write(agent_list->last()->get_name(), 64);
	cout << endl;
	*/
}

void GW2_CombatData::add_skill(GW2_Skill* skill_data)
{
	skill_list->append(skill_data);

	//Debugging
	/*
	using namespace std;
	cout << endl;
	cout << "NAME: ";
	cout.write(skill_list->last()->get_name(), 64);
	cout << endl;
	*/
}

void GW2_CombatData::add_combatevent(GW2_CombatEvent* combatevent_data)
{
	combatevent_list->append(combatevent_data);

	//Debugging
	/*
	using namespace std;
	cout << endl;
	cout << "NAME: ";
	cout.write(combatevent_list->last()->get_name(), 64);
	cout << endl;
	*/
}

void GW2_CombatData::clear_agents()
{
	qDeleteAll(agent_list->begin(), agent_list->end());
	agent_list->clear();
}

void GW2_CombatData::clear_skills()
{
	qDeleteAll(skill_list->begin(), skill_list->end());
	skill_list->clear();
}

void GW2_CombatData::clear_combatevents()
{
	qDeleteAll(combatevent_list->begin(), combatevent_list->end());
	combatevent_list->clear();
}

uint16_t  GW2_CombatData::get_upper_bytes(uint32_t number)
{
	//TODO: test output & verify
	//shift upper 
	uint16_t shifted_number = (number >> 16) & 0xffff;
	return shifted_number;
}
uint16_t  GW2_CombatData::get_lower_bytes(uint32_t number)
{
	//TODO: test output & verify
	uint16_t truncated_number = number & 0xffff;
	return truncated_number;
}

void GW2_CombatData::split_gadgets()
{	
	for (int counter = 0; counter < agent_list->size(); counter++)
	{
		//Check if entry is Gadget
		if ((agent_list->at(counter)->get_is_elite() == 0xffffffff) && get_upper_bytes(agent_list->at(counter)->get_prof()) == 0xffff)
		{
			//Agent is Gadget with volatile ID, Remove from Agents and add to Gadgets, assign ID
			//TODO add code to handle transfer and correct pointer position
			printf("Found a Gadget at Pos: %d\n",counter);			
		} 
		else
		{
			//TODO add code to handle transfer 			
		}
	}
}

void GW2_CombatData::split_characters()
{
	for (int counter = 0; counter < agent_list->size(); counter++)
	{
		//Check if entry is Character
		if ((agent_list->at(counter)->get_is_elite() == 0xffffffff) && get_upper_bytes(agent_list->at(counter)->get_prof()) != 0xffff)
		{
			//Agent is Character with species ID, Remove from Agents and add to Characters, assign ID
			//TODO add code to handle transfer and correct pointer position
			printf("Found a Character at Pos: %d\n", counter);
		}
		else
		{
			
		}
	}

}

void GW2_CombatData::split_players()
{
	for (int counter = 0; counter < agent_list->size(); counter++)
	{
		//Check if entry is Player
		if ((agent_list->at(counter)->get_is_elite() != 0xffffffff))
		{
			//Agent is Player with profession and elite spec, Remove from Agents and add to Players
			//TODO add code to handle transfer and correct pointer position
			printf("Found a Player at Pos: %d\n", counter);
			printf("Player pofession: %d\n", agent_list->at(counter)->get_prof());
			printf("Player elitespec: %d\n", agent_list->at(counter)->get_is_elite());
		}
		else
		{

		}
	}

}

void GW2_CombatData::assign_instance_id()
{	
	for (int event_counter = 0; event_counter < combatevent_list->size(); event_counter++){
		for (int agent_counter = 0; agent_counter < agent_list->size(); agent_counter++)
		{
			//If event belongs to agent assing id and times
			if ((agent_list->at(agent_counter)->get_addr() == combatevent_list->at(event_counter)->src_agent) && !combatevent_list->at(event_counter)->is_statechange)
			{				
				agent_list->at(agent_counter)->set_instance_id(combatevent_list->at(event_counter)->src_instid);				
				if (agent_list->at(agent_counter)->get_first_aware() == 0)
				{
					//Assign time to first_aware if first occurence
					agent_list->at(agent_counter)->set_first_aware(combatevent_list->at(event_counter)->time);
					//printf("Assigned first_aware to agent ID %d\n", agent_counter);
				}
				else
				{
					//Assign time to last_aware if not first occurence
					agent_list->at(agent_counter)->set_last_aware(combatevent_list->at(event_counter)->time);
					//printf("Assigned last_aware to agent ID %d\n", agent_counter);
				}
			}
		}		
	}
	printf("Assignment of ID's and first/last_aware times complete\n");
}

void GW2_CombatData::assign_master_agent()
{
	//For each combatevent
	for (int event_counter = 0; event_counter < combatevent_list->size(); event_counter++){
		//If the event has a master_id, the source is a minion/pet
		if (combatevent_list->at(event_counter)->src_master_instid != 0)
		{
			//Iterate through all agents
			for (int master_counter = 0; master_counter < agent_list->size(); master_counter++)
			{
				//Find the master agent for the combat event where instance id matches and master existed while event occurs 
				if (agent_list->at(master_counter)->get_instance_id() == combatevent_list->at(event_counter)->src_master_instid && (agent_list->at(master_counter)->get_first_aware() < combatevent_list->at(event_counter)->time < agent_list->at(master_counter)->get_last_aware()))
				{
					printf("Master ID is %X\n", agent_list->at(master_counter)->get_addr());
					//Find minion/pet agent executing the event by comparing agent addr to cbtevent src_agent  
					for (int minion_counter = 0; minion_counter < agent_list->size(); minion_counter++)
					{
						//If minion/pet agent was found assign master_addr to minion
						if (agent_list->at(minion_counter)->get_addr() == combatevent_list->at(event_counter)->src_agent)
						{
							printf("Minion ID is %X\n", agent_list->at(minion_counter)->get_addr());
							agent_list->at(minion_counter)->set_master_addr(agent_list->at(master_counter)->get_addr());
						}						
					}					
				}				
			}
		}		
	}
	printf("Assignment of Master ID's complete\n");
}

//
// SETTER BLOCK
//

void GW2_CombatData::set_build_version(std::string version_str)
{
	build_version = version_str;
}

void GW2_CombatData::set_pov(std::string pov_str)
{
	pov = pov_str;
}

void GW2_CombatData::set_log_start(std::string start_time)
{
	log_start = start_time;
}
void GW2_CombatData::set_log_end(std::string end_time)
{
	log_end = end_time;
}

void GW2_CombatData::set_boss_id(uint16_t id)
{
	boss_id = id;
}

//
// GETTER BLOCK
//

uint16_t  GW2_CombatData::get_boss_id()
{
	return boss_id;
}

//
// MAP MANAGEMENT
//

void GW2_CombatData::map_add_agent(GW2_Agent* agent_data)
{
	agent_map.insert(agent_data->get_addr(),agent_data);
}

void GW2_CombatData::clear_agent_map()
{
	agent_map.clear();
}

void GW2_CombatData::map_assign_instance_id()
{	
	for (int event_counter = 0; event_counter < combatevent_list->size(); event_counter++){
		//Generate small list of relevant agents
		QList<GW2_Agent*> working_agents = agent_map.values(combatevent_list->at(event_counter)->src_agent);
		
		for (int agent_counter = 0; agent_counter < working_agents.size(); agent_counter++)
		{
			//If event belongs to agent assing id and times
			if ((working_agents.at(agent_counter)->get_addr() == combatevent_list->at(event_counter)->src_agent) && !combatevent_list->at(event_counter)->is_statechange)
			{
				working_agents.at(agent_counter)->set_instance_id(combatevent_list->at(event_counter)->src_instid);
				if (working_agents.at(agent_counter)->get_first_aware() == 0)
				{
					//Assign time to first_aware if first occurence
					working_agents.at(agent_counter)->set_first_aware(combatevent_list->at(event_counter)->time);
					//printf("Assigned first_aware to agent ID %d = %d\n", working_agents.at(agent_counter)->get_addr(), combatevent_list->at(event_counter)->src_agent);
				}
				else
				{
					//Assign time to last_aware if not first occurence
					working_agents.at(agent_counter)->set_last_aware(combatevent_list->at(event_counter)->time);
					//printf("Assigned last_aware to agent ID %d\n", agent_counter);
				}
			}
		}		
	}
	printf("Assignment of ID's and first/last_aware times complete\n");
}

void GW2_CombatData::map_assign_master_agent()
{
	//For each combatevent
	for (int event_counter = 0; event_counter < combatevent_list->size(); event_counter++){
		//If the event has a master_id, the source is a minion/pet
		if (combatevent_list->at(event_counter)->src_master_instid != 0)
		{			
			//Generate list of all agents
			QList<GW2_Agent*> working_agents = agent_map.values();			

			//Iterate through all agents
			for (int master_counter = 0; master_counter < working_agents.size(); master_counter++)
			{
				//Find the master agent for the combat event where instance id matches and master existed while event occurs 
				if (working_agents.at(master_counter)->get_instance_id() == combatevent_list->at(event_counter)->src_master_instid && (working_agents.at(master_counter)->get_first_aware() < combatevent_list->at(event_counter)->time < working_agents.at(master_counter)->get_last_aware()))
				{
					printf("Master ID is %X\n", working_agents.at(master_counter)->get_addr());
					
					//Generate small list of relevant minion agents
					QList<GW2_Agent*> working_minions = agent_map.values(combatevent_list->at(event_counter)->src_agent);

					//Find minion/pet agent executing the event by comparing agent addr to cbtevent src_agent  
					for (int minion_counter = 0; minion_counter < working_minions.size(); minion_counter++)
					{
						//If minion/pet agent was found assign master_addr to minion
						if (working_minions.at(minion_counter)->get_addr() == combatevent_list->at(event_counter)->src_agent)
						{
							printf("Minion ID is %X\n", working_minions.at(minion_counter)->get_addr());
							working_minions.at(minion_counter)->set_master_addr(working_agents.at(master_counter)->get_addr());
						}
					}
				}
			}
		}
	}
	printf("Assignment of Master ID's complete\n");
}