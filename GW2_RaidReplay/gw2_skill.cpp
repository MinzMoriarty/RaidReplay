#include "gw2_skill.h"

GW2_Skill::GW2_Skill(QObject *parent)
	: QObject(parent)
{
}

GW2_Skill::GW2_Skill(QObject *parent, int32_t c_id, char* c_name)
	: QObject(parent)
{
	id = c_id;	
	strncpy(name, c_name, 64);
}

GW2_Skill::~GW2_Skill()
{
}
