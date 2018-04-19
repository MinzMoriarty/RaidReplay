#include "gw2_agent.h"

GW2_Agent::GW2_Agent(QObject *parent)
	: QObject(parent)
{
	addr = 0;
	prof = 0;
	is_elite = 0;
	toughness = 0;
	concentration = 0;
	healing = 0;
	pad1 = 0;
	condition = 0;
	pad2 = 0;	
}

GW2_Agent::GW2_Agent(QObject *parent, uint64_t c_addr, uint32_t c_prof, uint32_t c_is_elite, int16_t c_toughness, int16_t c_concentration, int16_t c_healing, int16_t c_pad1, int16_t c_condition, int16_t c_pad2, char* c_name)
	: QObject(parent)
{
	addr = c_addr;
	prof = c_prof;	
	is_elite = c_is_elite;
	toughness = c_toughness;
	concentration = c_concentration;
	healing = c_healing;
	pad1 = c_pad1;
	condition = c_condition;
	pad2 = c_pad2;
	strncpy(name, c_name, 64);
	instance_id = 0;
	first_aware = 0;
	last_aware = UINT64_MAX;
	master_addr = 0;
}

// GETTER

uint64_t GW2_Agent::get_addr()
{
	return addr;
}

uint32_t GW2_Agent::get_prof()
{
	return prof;
}

uint32_t GW2_Agent::get_is_elite()
{
	return is_elite;
}

int16_t GW2_Agent::get_toughness()
{
	return toughness;
}

int16_t GW2_Agent::get_concentration()
{
	return concentration;
}

int16_t GW2_Agent::get_healing()
{
	return healing;
}

int16_t GW2_Agent::get_pad1()
{
	return pad1;
}

int16_t GW2_Agent::get_condition()
{
	return condition;
}

int16_t GW2_Agent::get_pad2()
{
	return pad2;
}

char* GW2_Agent::get_name()
{
	return name;
}

uint16_t GW2_Agent::get_instance_id()
{
	return instance_id;
}

uint64_t GW2_Agent::get_first_aware()
{
	return first_aware;
}

uint64_t GW2_Agent::get_last_aware()
{
	return last_aware;
}

uint64_t GW2_Agent::get_master_addr()
{
	return master_addr;
}

//SETTER

void GW2_Agent::set_instance_id(uint16_t i_id)
{
	instance_id = i_id;
}

void GW2_Agent::set_first_aware(uint64_t f_aw)
{
	first_aware = f_aw;
}

void GW2_Agent::set_last_aware(uint64_t l_aw)
{
	last_aware = l_aw;
}

void GW2_Agent::set_master_addr(uint64_t m_addr)
{
	master_addr = m_addr;
}

GW2_Agent::~GW2_Agent()
{
}
