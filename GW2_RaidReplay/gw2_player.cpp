#include "gw2_player.h"

GW2_Player::GW2_Player(QObject *parent)	
	: GW2_Agent(parent)
{

}

GW2_Player::GW2_Player(QObject *parent, GW2_Agent* agent)
	: GW2_Agent(parent)
{
	//GW2_Agent shared variables
	addr = agent->get_addr();	
	prof = agent->get_prof();
	is_elite = agent->get_is_elite();
	toughness = agent->get_toughness();
	concentration = agent->get_concentration();
	healing = agent->get_healing();
	pad1 = agent->get_pad1();
	condition = agent->get_condition();
	pad2 = agent->get_pad2();
	memcpy(name, agent->get_name(), 64 * sizeof(char));	
	instance_id = agent->get_instance_id();
	first_aware = agent->get_first_aware();
	last_aware = agent->get_last_aware();;
	master_addr = agent->get_master_addr();
	//Handle GW2_Player specific variables
	split_name();	

	minion_map = agent->minion_map;
	incoming_events = agent->incoming_events;
	outgoing_events = agent->outgoing_events;
	
	//TODO: Handle map data copying diffently?
}

GW2_Player::~GW2_Player()
{
}

void GW2_Player::split_name()
{
	char namestring[64];
	memcpy(namestring, name, 64 * sizeof(char));
	
	char* cp;
	
	int select = 0;
	
	//Copy cstring contents for character name
	strcpy(character_name, namestring);

	for (int i = 0; (i < 64) && (select < 2) ; i++)
	{
		if (namestring[i] == '\0')
		{
			//Copy cstring contents from the range (cp -> next '\0') into the respective array	
			switch (select) 
			{
				case 0:
					//adjust cp to trim leading ':' from account name
					cp = &namestring[i + 2];
					strcpy(account_name, cp);
					select++;
					break;

				case 1:
					cp = &namestring[i + 1];
					strcpy(subgroup, cp);
					select++;
					break;			

				default:
					//printf("This never happens! \n");
					break;
			}
		}
	}
	printf("Character Name: %s \n", character_name);
	printf("Account Name: %s \n", account_name);
	printf("Subgroup: %s \n", subgroup);
}

char* GW2_Player::get_character_name()
{
	return character_name;
}

char* GW2_Player::get_account_name()
{
	return account_name;
}

char* GW2_Player::get_subgroup()
{
	return subgroup;
}