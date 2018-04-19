#pragma once

#include <QObject>
#include <stdint.h>

class GW2_CombatEvent : public QObject
{
	Q_OBJECT

public:
	GW2_CombatEvent(QObject *parent);
	GW2_CombatEvent(QObject *parent, uint64_t c_time, uint64_t c_src_agent, uint64_t c_dst_agent, int32_t c_value, int32_t c_buff_dmg, uint16_t c_overstack_value, uint16_t c_skillid, uint16_t c_src_instid, 
		uint16_t c_dst_instid, uint16_t c_src_master_instid, uint8_t c_iss_offset,uint8_t c_iss_offset_target, uint8_t c_iss_bd_offset, uint8_t c_iss_bd_offset_target, uint8_t c_iss_alt_offset, 
		uint8_t c_iss_alt_offset_target, uint8_t c_skar, uint8_t c_skar_alt, uint8_t c_skar_use_alt, uint8_t c_iff, uint8_t c_buff, uint8_t c_result, uint8_t c_is_activation, uint8_t c_is_buffremove, 
		uint8_t c_is_ninety, uint8_t c_is_fifty, uint8_t c_is_moving, uint8_t c_is_statechange, uint8_t c_is_flanking, uint8_t c_is_shields, uint8_t c_result_local, uint8_t c_ident_local);
	~GW2_CombatEvent();

	uint64_t time; /* timegettime() at time of event */
	uint64_t src_agent; /* unique identifier */
	uint64_t dst_agent; /* unique identifier */
	int32_t value; /* event-specific */
	int32_t buff_dmg; /* estimated buff damage. zero on application event */
	uint16_t overstack_value; /* estimated overwritten stack duration for buff application */
	uint16_t skillid; /* skill id */
	uint16_t src_instid; /* agent map instance id */
	uint16_t dst_instid; /* agent map instance id */
	uint16_t src_master_instid; /* master source agent map instance id if source is a minion/pet */
	uint8_t iff; /* from iff enum */
	uint8_t buff; /* buff application, removal, or damage event */
	uint8_t result; /* from cbtresult enum */
	uint8_t is_activation; /* from cbtactivation enum */
	uint8_t is_buffremove; /* buff removed. src=relevant, dst=caused it (for strips/cleanses). from cbtr enum */
	uint8_t is_ninety; /* source agent health was over 90% */
	uint8_t is_fifty; /* target agent health was under 50% */
	uint8_t is_moving; /* source agent was moving */
	uint8_t is_statechange; /* from cbtstatechange enum */
	uint8_t is_flanking; /* target agent was not facing source */
	uint8_t is_shields; /* all or part damage was vs barrier/shield */
	
private:
	//unused variables
	uint8_t result_local; /* internal tracking. garbage */
	uint8_t ident_local; /* internal tracking. garbage */
	uint8_t iss_offset; /* internal tracking. garbage */
	uint8_t iss_offset_target; /* internal tracking. garbage */
	uint8_t iss_bd_offset; /* internal tracking. garbage */
	uint8_t iss_bd_offset_target; /* internal tracking. garbage */
	uint8_t iss_alt_offset; /* internal tracking. garbage */
	uint8_t iss_alt_offset_target; /* internal tracking. garbage */
	uint8_t skar; /* internal tracking. garbage */
	uint8_t skar_alt; /* internal tracking. garbage */
	uint8_t skar_use_alt; /* internal tracking. garbage */

};
