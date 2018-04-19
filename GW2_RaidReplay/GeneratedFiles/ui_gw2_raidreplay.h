/********************************************************************************
** Form generated from reading UI file 'gw2_raidreplay.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GW2_RAIDREPLAY_H
#define UI_GW2_RAIDREPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GW2_RaidReplayClass
{
public:
    QAction *actionOpen;
    QAction *actionReload;
    QAction *actionArena_View;
    QAction *actionDPS_Tables;
    QAction *actionBoon_Stats;
    QAction *actionMechanics;
    QWidget *centralWidget;
    QPushButton *pushButtonTest;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuAnalysis;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GW2_RaidReplayClass)
    {
        if (GW2_RaidReplayClass->objectName().isEmpty())
            GW2_RaidReplayClass->setObjectName(QStringLiteral("GW2_RaidReplayClass"));
        GW2_RaidReplayClass->resize(600, 400);
        actionOpen = new QAction(GW2_RaidReplayClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionReload = new QAction(GW2_RaidReplayClass);
        actionReload->setObjectName(QStringLiteral("actionReload"));
        actionArena_View = new QAction(GW2_RaidReplayClass);
        actionArena_View->setObjectName(QStringLiteral("actionArena_View"));
        actionDPS_Tables = new QAction(GW2_RaidReplayClass);
        actionDPS_Tables->setObjectName(QStringLiteral("actionDPS_Tables"));
        actionBoon_Stats = new QAction(GW2_RaidReplayClass);
        actionBoon_Stats->setObjectName(QStringLiteral("actionBoon_Stats"));
        actionMechanics = new QAction(GW2_RaidReplayClass);
        actionMechanics->setObjectName(QStringLiteral("actionMechanics"));
        centralWidget = new QWidget(GW2_RaidReplayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonTest = new QPushButton(centralWidget);
        pushButtonTest->setObjectName(QStringLiteral("pushButtonTest"));
        pushButtonTest->setGeometry(QRect(230, 80, 75, 23));
        GW2_RaidReplayClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GW2_RaidReplayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAnalysis = new QMenu(menuBar);
        menuAnalysis->setObjectName(QStringLiteral("menuAnalysis"));
        GW2_RaidReplayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GW2_RaidReplayClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GW2_RaidReplayClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GW2_RaidReplayClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GW2_RaidReplayClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuAnalysis->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionReload);
        menuView->addAction(actionArena_View);
        menuView->addAction(actionDPS_Tables);
        menuView->addAction(actionBoon_Stats);
        menuView->addAction(actionMechanics);

        retranslateUi(GW2_RaidReplayClass);

        QMetaObject::connectSlotsByName(GW2_RaidReplayClass);
    } // setupUi

    void retranslateUi(QMainWindow *GW2_RaidReplayClass)
    {
        GW2_RaidReplayClass->setWindowTitle(QApplication::translate("GW2_RaidReplayClass", "GW2_RaidReplay", nullptr));
        actionOpen->setText(QApplication::translate("GW2_RaidReplayClass", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("GW2_RaidReplayClass", "Open EVTC File", nullptr));
#endif // QT_NO_TOOLTIP
        actionReload->setText(QApplication::translate("GW2_RaidReplayClass", "Reload", nullptr));
        actionArena_View->setText(QApplication::translate("GW2_RaidReplayClass", "Arena View", nullptr));
        actionDPS_Tables->setText(QApplication::translate("GW2_RaidReplayClass", "DPS Tables", nullptr));
        actionBoon_Stats->setText(QApplication::translate("GW2_RaidReplayClass", "Boon Tables", nullptr));
        actionMechanics->setText(QApplication::translate("GW2_RaidReplayClass", "Mechanics", nullptr));
        pushButtonTest->setText(QApplication::translate("GW2_RaidReplayClass", "Parse", nullptr));
        menuFile->setTitle(QApplication::translate("GW2_RaidReplayClass", "File", nullptr));
        menuView->setTitle(QApplication::translate("GW2_RaidReplayClass", "View", nullptr));
        menuAnalysis->setTitle(QApplication::translate("GW2_RaidReplayClass", "Analysis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GW2_RaidReplayClass: public Ui_GW2_RaidReplayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GW2_RAIDREPLAY_H
