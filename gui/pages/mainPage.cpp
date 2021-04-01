/*
 * wmain.cpp
 *
 *  Created on: 25/01/2017
 *      Author: john
 */

#include "gui/pages/mainPage.h"

mainPage::mainPage(QWidget* parent) :
QWidget(parent),
mUi(new Ui::mainPage){
	mUi->setupUi(this);
	connect(mUi->pbCountBalance, SIGNAL(clicked()), this, SLOT(countBalance()));
	connect(mUi->pbSetMonthFolder, SIGNAL(clicked()), this, SLOT(setMonthFolder()));
	MainExcelXLS::initMainExcelXLS();
}

mainPage::~mainPage() {
	delete mUi;
}

void mainPage::setMonthFolder(){
	QString folder = QFileDialog::getExistingDirectory(this, tr("Seleccionar Carpeta"), lastMonthFolder.toLocal8Bit().constData());
	if(!folder.isNull()){
		mUi->txtMonthFolder->setText(folder);
		lastMonthFolder = folder;
	}
}

void mainPage::countBalance(){
	int balance = MainExcelXLS::calculateBalance(mUi->calendar->selectedDate().toString(Qt::ISODate).toUtf8().constData(), 
					lastMonthFolder.toUtf8().constData());
	return;
}
