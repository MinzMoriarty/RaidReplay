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

GW2_Skill::GW2_Skill(QObject *parent, skill s_skill)
	: QObject(parent)
{
	id = s_skill.id;	
	memcpy(name, s_skill.name, 64 * sizeof(char));
}

GW2_Skill::~GW2_Skill()
{
}
