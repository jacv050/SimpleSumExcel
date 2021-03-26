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
}

mainPage::~mainPage() {
	delete mUi;
}

void mainPage::countBalance(){
	return;
}
