#include "gw2_combatevent.h"

GW2_CombatEvent::GW2_CombatEvent(QObject *parent)
	: QObject(parent)
{
}

GW2_CombatEvent::GW2_CombatEvent(QObject *parent, uint64_t c_time, uint64_t c_src_agent, uint64_t c_dst_agent, int32_t c_value, int32_t c_buff_dmg, uint16_t c_overstack_value, uint16_t c_skillid, uint16_t c_src_instid,
	uint16_t c_dst_instid, uint16_t c_src_master_instid, uint8_t c_iss_offset, uint8_t c_iss_offset_target, uint8_t c_iss_bd_offset, uint8_t c_iss_bd_offset_target, uint8_t c_iss_alt_offset,
	uint8_t c_iss_alt_offset_target, uint8_t c_skar, uint8_t c_skar_alt, uint8_t c_skar_use_alt, uint8_t c_iff, uint8_t c_buff, uint8_t c_result, uint8_t c_is_activation, uint8_t c_is_buffremove,
	uint8_t c_is_ninety, uint8_t c_is_fifty, uint8_t c_is_moving, uint8_t c_is_statechange, uint8_t c_is_flanking, uint8_t c_is_shields, uint8_t c_result_local, uint8_t c_ident_local)
	: QObject(parent)
{
	time = c_time;
	src_agent = c_src_agent;
	dst_agent = c_dst_agent;
	value = c_value;
	buff_dmg = c_buff_dmg;
	overstack_value = c_overstack_value;
	skillid = c_skillid;
	src_instid = c_src_instid;
	dst_instid = c_dst_instid;
	src_master_instid = c_src_master_instid;
	iss_offset = c_iss_offset;
	iss_offset_target = c_iss_offset_target;
	iss_bd_offset = c_iss_bd_offset;
	iss_bd_offset_target = c_iss_bd_offset_target;
	iss_alt_offset = c_iss_alt_offset;
	iss_alt_offset_target = c_iss_alt_offset_target;
	skar = c_skar;
	skar_alt = c_skar_alt;
	skar_use_alt = c_skar_use_alt;
	iff = c_iff;
	buff = c_buff;
	result = c_result;
	is_activation = c_is_activation;
	is_buffremove = c_is_buffremove;
	is_ninety = c_is_ninety;
	is_fifty = c_is_fifty;
	is_moving = c_is_moving;
	is_statechange = c_is_statechange;
	is_flanking = c_is_flanking;
	is_shields = c_is_shields;
	result_local = c_result_local;
	ident_local = c_ident_local;
}

GW2_CombatEvent::GW2_CombatEvent(QObject *parent, cbtevent s_event)
	: QObject(parent)
{
	time = s_event.time;
	src_agent = s_event.src_agent;
	dst_agent = s_event.dst_agent;
	value = s_event.value;
	buff_dmg = s_event.buff_dmg;
	overstack_value = s_event.overstack_value;
	skillid = s_event.skillid;
	src_instid = s_event.src_instid;
	dst_instid = s_event.dst_instid;
	src_master_instid = s_event.src_master_instid;
	iss_offset = s_event.iss_offset;
	iss_offset_target = s_event.iss_offset_target;
	iss_bd_offset = s_event.iss_bd_offset;
	iss_bd_offset_target = s_event.iss_bd_offset_target;
	iss_alt_offset = s_event.iss_alt_offset;
	iss_alt_offset_target = s_event.iss_alt_offset_target;
	skar = s_event.skar;
	skar_alt = s_event.skar_alt;
	skar_use_alt = s_event.skar_use_alt;
	iff = s_event.iff;
	buff = s_event.buff;
	result = s_event.result;
	is_activation = s_event.is_activation;
	is_buffremove = s_event.is_buffremove;
	is_ninety = s_event.is_ninety;
	is_fifty = s_event.is_fifty;
	is_moving = s_event.is_moving;
	is_statechange = s_event.is_statechange;
	is_flanking = s_event.is_flanking;
	is_shields = s_event.is_shields;
	result_local = s_event.result_local;
	ident_local = s_event.ident_local;
}

GW2_CombatEvent::~GW2_CombatEvent()
{
}
