#ifndef MAINEXCELXLS_H
#define MAINEXCELXLS_H
#pragma once
#include "src/SettingsLoader.hpp"
#include <ExcelFormat/ExcelFormat.h>
#include "boost/filesystem.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <stdlib.h> 
#include "utils.hpp"

class MainExcelXLS
{
	private:	
		MainExcelXLS();
		~MainExcelXLS();
		SettingsLoader settings;
		static MainExcelXLS* mainExcelXLS;
		static void splitCell(const std::string& cell, std::string& row, std::string& col);

	public:
		MainExcelXLS(MainExcelXLS&) = delete;
		void operator=(MainExcelXLS&) = delete;
		static void initMainExcelXLS();
		//Date en format year/day/month
		static int calculateBalance(const std::string& date, const std::string& excelsFolder);

};
#endif