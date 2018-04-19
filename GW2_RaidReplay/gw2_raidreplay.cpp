#include "gw2_raidreplay.h"


GW2_RaidReplay::GW2_RaidReplay(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonTest, SIGNAL(clicked()), this, SLOT(ParseButtonClicked()));
}

GW2_RaidReplay::~GW2_RaidReplay()
{
	
}

void GW2_RaidReplay::on_actionOpen_triggered()
{
	std::cout << "Triggered : Open\n";
}

void GW2_RaidReplay::ParseButtonClicked()
{
	std::cout << "Triggered : Parse Button\n";
	GW2_CombatData dataset(this);
	GW2_Evtc_Parser parser(this, &dataset);
	parser.parse_evtc_log();
	dataset.map_assign_instance_id();
	dataset.map_assign_master_agent();
	//dataset.assign_instance_id();
	//dataset.assign_master_agent();
	//dataset.split_gadgets();
	//dataset.split_characters();
	//dataset.split_players();
}