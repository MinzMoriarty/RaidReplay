#include "gw2_raidreplay.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GW2_RaidReplay w;	
	w.show();
	return a.exec();
}
