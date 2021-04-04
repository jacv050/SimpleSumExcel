#ifndef MAINEXCELXLS_H
#define MAINEXCELXLS_H
#pragma once
#include "src/SettingsLoader.hpp"
#include <xlnt/xlnt.hpp>
#include "boost/filesystem.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <stdlib.h> 
#include "utils.hpp"
#include "ExcelFormat/ExcelFormat.h"
#include "boost/date_time/posix_time/posix_time.hpp"

class MainExcel
{
	private:	
		MainExcel();
		~MainExcel();
		SettingsLoader settings;
		static MainExcel* mainExcelXLS;
		static boost::posix_time::ptime datetime_ole_to_posix(long ole_dt);

	public:
		MainExcel(MainExcel&) = delete;
		void operator=(MainExcel&) = delete;
		static void initMainExcel();
		//Date en format year/day/month
		static double calculateBalance(const std::string& date, const std::string& excelsFolder);
		//Credential reader
		static void processCredential(const std::wstring& cred, std::wstring& id, std::wstring& limit);
		//sheet index from limit and sheet arrays
		static int getSheetIndex(const std::string& limit);
		static std::string getMonthFolder();
		static void saveMonthFolder(const std::string& monthFolder);

};
#endif