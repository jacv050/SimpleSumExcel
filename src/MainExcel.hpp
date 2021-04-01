#ifndef MAINEXCELXLS_H
#define MAINEXCELXLS_H
#pragma once
#include "src/SettingsLoader.hpp"
#include <ExcelFormat/ExcelFormat.h>
#include "boost/filesystem.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <stdlib.h> 
#include "utils.hpp"

class MainExcel
{
	private:	
		MainExcel();
		~MainExcel();
		SettingsLoader settings;
		static MainExcel* mainExcelXLS;
		static void splitCell(const std::string& cell, std::string& row, std::string& col);

	public:
		MainExcel(MainExcel&) = delete;
		void operator=(MainExcel&) = delete;
		static void initMainExcel();
		//Date en format year/day/month
		static int calculateBalance(const std::string& date, const std::string& excelsFolder);

};
#endif