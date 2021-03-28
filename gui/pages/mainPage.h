/*
 * wmain.h
 *
 *  Created on: 25/01/2017
 *      Author: john
 */

#ifndef WMAIN_H_
#define WMAIN_H_

#include <QtWidgets>
#include "ui_mainPage.h"
#include "gui/gui.h"
#include "src/SettingsLoader.hpp"

/**
 * Page to select the tool
 */
class mainPage : public QWidget {
	Q_OBJECT
public:
	mainPage(QWidget* parent = 0);
	virtual ~mainPage();

private:
	Ui::mainPage *mUi;
	SettingsLoader settings;

private slots:
    void countBalance();
};

#endif /* WMAIN_H_ */
