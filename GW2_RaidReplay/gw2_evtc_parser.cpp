#include "gw2_evtc_parser.h"

GW2_Evtc_Parser::GW2_Evtc_Parser(QObject *parent, GW2_CombatData* dataset)
	: QObject(parent)
{
	fIndex = 0;
	dataset_addr = dataset;
}

GW2_Evtc_Parser::~GW2_Evtc_Parser()
{
}

void GW2_Evtc_Parser::parse_evtc_log()
{
	parse_evtc_header();
	parse_evtc_agents();
	parse_evtc_skills();
	parse_evtc_cbtevents();	
}

void GW2_Evtc_Parser::parse_evtc_header()
{
	FILE * pFile;
	size_t result;

	// TODO : add variable filename after testing
	pFile = fopen("testfile1.evtc", "rb");

	if (pFile == NULL)
	{
		fputs("File error", stderr);
	}

	rewind(pFile);

	// read versioning string, first 12 bytes of the file
	char evtc_version[12];
	result = fread(evtc_version, 1, 12, pFile);

	// DEBUG output
	cout << "EVTC Version: ";
	cout.write(evtc_version, 12);
	cout << endl;
	dataset_addr->set_build_version(evtc_version);

	uint16_t boss_id;
	fseek(pFile, 13, SEEK_SET);
	result = fread(&boss_id, sizeof(boss_id), 1, pFile);
	dataset_addr->set_boss_id(boss_id);

	// DEBUG output - Warning: enabling slows down program considerably	
	cout << "Boss ID: 0x" << hex << boss_id << dec << endl;

	// terminate
	fclose(pFile);
}

void GW2_Evtc_Parser::parse_evtc_agents()
{
	typedef struct evtc_agent {
		uint64_t addr;
		uint32_t prof;
		uint32_t is_elite;
		int16_t toughness;
		int16_t concentration;
		int16_t healing;
		int16_t pad1;
		int16_t condition;
		int16_t pad2;
		char name[64];
	} evtc_agent;

	FILE * pFile;
	size_t result;
	fIndex = 16;

	pFile = fopen("testfile1.evtc", "rb");
	if (pFile == NULL)
	{
		fputs("File error", stderr);
	}

	// Start after Header
	fseek(pFile, fIndex, SEEK_SET);

	uint32_t agent_count;
	result = fread(&agent_count, sizeof(agent_count), 1, pFile);

	// DEBUG output
	cout << endl << "Agent Count: " << agent_count << endl;

	evtc_agent agent_buffer;

	fIndex += sizeof(agent_count);

	fseek(pFile, fIndex, SEEK_SET);

	//Debugging Remove for complete parsing
	//agent_count = 50;

	for (int counter = 0; counter < agent_count; counter++)
	{
		result = fread(&agent_buffer, sizeof(evtc_agent), 1, pFile);
		dataset_addr->add_agent(new GW2_Agent(dataset_addr, agent_buffer.addr, agent_buffer.prof, agent_buffer.is_elite, agent_buffer.toughness, agent_buffer.concentration, agent_buffer.healing, agent_buffer.pad1, agent_buffer.condition, agent_buffer.pad2, agent_buffer.name));

		// DEBUG output - Warning: enabling slows down program considerably	
		/*
		cout << endl;
		cout << "NAME: ";
		cout.write(agent_buffer.name, 64);
		cout << endl;
		cout << "ADDR: " << hex << agent_buffer.addr << dec << endl;
		cout << "PROF: " << agent_buffer.prof << endl;
		cout << "ELITE: " << agent_buffer.is_elite << endl;
		cout << "Toughness: " << agent_buffer.toughness << endl;
		cout << "Concentration: " << agent_buffer.concentration << endl;
		cout << "Healing: " << agent_buffer.healing << endl;
		cout << "Condition Damage: " << agent_buffer.condition << endl;
		cout << "Pad1: " << agent_buffer.pad1 << endl;
		cout << "Pad2: " << agent_buffer.pad2 << endl;
		*/

		fIndex += sizeof(evtc_agent);
	}
	// terminate
	fclose(pFile);
}

void GW2_Evtc_Parser::parse_evtc_skills()
{
	typedef struct skill {
		int32_t id;
		char name[64];
	} skill;

	FILE * pFile;
	size_t result;

	pFile = fopen("testfile1.evtc", "rb");
	if (pFile == NULL)
	{
		fputs("File error", stderr);
	}

	// Start after agents; only run after parse_evtc_agents() to set right index
	fseek(pFile, fIndex, SEEK_SET);

	uint32_t skill_count;
	result = fread(&skill_count, sizeof(skill_count), 1, pFile);

	// DEBUG output
	cout << endl << "Skill Count: " << skill_count << endl;

	skill skill_buffer;

	fIndex += sizeof(skill_count);

	fseek(pFile, fIndex, SEEK_SET);

	//Debugging Remove for complete parsing
	//skill_count = 50;

	cout << "############ SKILLS ############" << endl;

	for (int counter = 0; counter < skill_count; counter++)
	{

		result = fread(&skill_buffer, sizeof(skill), 1, pFile);
		dataset_addr->add_skill(new GW2_Skill(dataset_addr, skill_buffer.id, skill_buffer.name));

		// DEBUG output - Warning: enabling slows down program considerably
		/*
		cout << "ID : " << skill_buffer.id;
		cout << endl;
		cout << "SKILL Name: ";
		cout.write(skill_buffer.name, 64);
		cout << endl << endl;
		*/

		fIndex += sizeof(skill);

	}
	// terminate
	fclose(pFile);
}

void GW2_Evtc_Parser::parse_evtc_cbtevents()
{
	typedef struct cbtevent {
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
		uint8_t iss_offset; /* internal tracking. garbage */
		uint8_t iss_offset_target; /* internal tracking. garbage */
		uint8_t iss_bd_offset; /* internal tracking. garbage */
		uint8_t iss_bd_offset_target; /* internal tracking. garbage */
		uint8_t iss_alt_offset; /* internal tracking. garbage */
		uint8_t iss_alt_offset_target; /* internal tracking. garbage */
		uint8_t skar; /* internal tracking. garbage */
		uint8_t skar_alt; /* internal tracking. garbage */
		uint8_t skar_use_alt; /* internal tracking. garbage */
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
		uint8_t result_local; /* internal tracking. garbage */
		uint8_t ident_local; /* internal tracking. garbage */
	} cbtevent;

	FILE * pFile;
	size_t result;

	pFile = fopen("testfile1.evtc", "rb");
	if (pFile == NULL)
	{
		fputs("File error", stderr);
	}
	// set pointer to End of File
	fseek(pFile, 0, SEEK_END);
	// find full size of the file
	long file_size = ftell(pFile);

	// Start after skills; only run after parse_evtc_skills() to set right index
	fseek(pFile, fIndex, SEEK_SET);

	//combat event block size is full size - pointer pos after other blocks
	long cbtevent_block_size = file_size - ftell(pFile);

	uint32_t cbtevent_count = cbtevent_block_size / sizeof(cbtevent);

	// DEBUG output
	// cout << endl << "cbtevent_block_size: " << cbtevent_block_size << endl;
	// cout << endl << "sizeof(cbtevent): " << sizeof(cbtevent) << endl;
	cout << endl << "Combat Event Count: " << cbtevent_count << endl;

	cbtevent cbtevent_buffer;

	//Debugging Remove for complete parsing
	//cbtevent_count = 5;

	cout << "############ COMBAT EVENTS ############" << endl;

	for (int counter = 0; counter < cbtevent_count; counter++)
	{
		result = fread(&cbtevent_buffer, sizeof(cbtevent), 1, pFile);
		dataset_addr->add_combatevent(new GW2_CombatEvent(dataset_addr, cbtevent_buffer.time, cbtevent_buffer.src_agent, cbtevent_buffer.dst_agent, cbtevent_buffer.value, cbtevent_buffer.buff_dmg, cbtevent_buffer.overstack_value, cbtevent_buffer.skillid, cbtevent_buffer.src_instid,
			cbtevent_buffer.dst_instid, cbtevent_buffer.src_master_instid, cbtevent_buffer.iss_offset, cbtevent_buffer.iss_offset_target, cbtevent_buffer.iss_bd_offset, cbtevent_buffer.iss_bd_offset_target, cbtevent_buffer.iss_alt_offset,
			cbtevent_buffer.iss_alt_offset_target, cbtevent_buffer.skar, cbtevent_buffer.skar_alt, cbtevent_buffer.skar_use_alt, cbtevent_buffer.iff, cbtevent_buffer.buff, cbtevent_buffer.result, cbtevent_buffer.is_activation, cbtevent_buffer.is_buffremove,
			cbtevent_buffer.is_ninety, cbtevent_buffer.is_fifty, cbtevent_buffer.is_moving, cbtevent_buffer.is_statechange, cbtevent_buffer.is_flanking, cbtevent_buffer.is_shields, cbtevent_buffer.result_local, cbtevent_buffer.ident_local));

		// DEBUG output - Warning: enabling slows down program considerably	
		/*
		cout << "TIME : " << cbtevent_buffer.time << endl;
		cout << "SRC Agent: " << cbtevent_buffer.src_agent << endl;
		cout << "DST Agent: " << cbtevent_buffer.dst_agent << endl;
		cout << "Value: " << cbtevent_buffer.value << endl;
		cout << endl;
		*/

		fIndex += sizeof(cbtevent);
	}

	//Sanity check : Did we read to the very end of the file?
	fseek(pFile, 0, SEEK_END);
	if (fIndex == ftell(pFile))
	{
		cout << "Reached EOF!" << endl;
	}
	else
	{
		cout << "Something went wrong! EOF does not match Index" << endl;
	}

	// terminate
	fclose(pFile);

}


void GW2_Evtc_Parser::parse_evtc_header_alt()
{
	/*
	// OBSOLETE: Tests for alternative parser strategy; read entire file, reconstruct from buffer
	*/

	FILE * pFile;
	long lSize;
	char * buffer;
	size_t result;

	pFile = fopen("testfile.evtc", "rb");

	if (pFile == NULL)
	{
		fputs("File error", stderr);
	}

	// obtain file size:
	// set pointer to End of File
	fseek(pFile, 0, SEEK_END);
	// find full size of the file
	lSize = ftell(pFile);
	// Set pointer to start of file
	rewind(pFile);

	// allocate memory to contain the header:
	buffer = (char*)malloc(sizeof(char)*lSize);

	if (buffer == NULL)
	{
		fputs("Memory error", stderr);
	}

	// copy the file into the buffer:
	result = fread(buffer, 1, lSize, pFile);

	if (result != lSize)
	{
		fputs("Reading error", stderr);
	}

	// DEBUG output
	cout.write(buffer, 12);

	// bitshift workaround to reconstruct uint16_t
	uint16_t boss_id = buffer[13] | buffer[14] << 8;

	// DEBUG output
	cout << endl << hex << boss_id << endl;

	// reconstruct agent count
	uint32_t agent_count = buffer[16] | buffer[17] << 8 | buffer[18] << 16 | buffer[19] << 24;

	cout << agent_count << endl;

	// terminate
	fclose(pFile);

	//not necessary since buffer in function currently
	free(buffer);
}

