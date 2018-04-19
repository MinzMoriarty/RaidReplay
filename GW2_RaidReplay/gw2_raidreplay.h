#ifndef GW2_RAIDREPLAY_H
#define GW2_RAIDREPLAY_H

#include <QtWidgets/QMainWindow>
#include "ui_gw2_raidreplay.h"
#include <QFileDialog>
#include <iostream>
#include "gw2_evtc_parser.h"
#include "gw2_combatdata.h"

class GW2_RaidReplay : public QMainWindow
{
	Q_OBJECT

public:
	GW2_RaidReplay(QWidget *parent = 0);
	~GW2_RaidReplay();
	GW2_CombatData dps_log_data(QWidget *parent = 0);

public slots:
	void on_actionOpen_triggered();
	void ParseButtonClicked();

private:
	Ui::GW2_RaidReplayClass ui;	
	
};

#endif // GW2_RAIDREPLAY_H
