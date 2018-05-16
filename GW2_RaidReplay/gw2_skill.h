#pragma once

#include <QObject>
#include <stdint.h>
#include "structs.h"

class GW2_Skill : public QObject
{
	Q_OBJECT

public:
	GW2_Skill(QObject *parent);
	GW2_Skill(QObject *parent, int32_t c_id, char* c_name);
	GW2_Skill(QObject *parent, skill s_skill);
	~GW2_Skill();

private:
	int32_t id;
	char name[64];

};
