#pragma once

#include "gw2_agent.h"

class GW2_Character : public GW2_Agent
{
	Q_OBJECT
	
public:
	GW2_Character(QObject *parent);
	~GW2_Character();
};
