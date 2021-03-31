#ifndef SETTINGSLOADER_H
#define SETTINGSLOADER_H
#pragma once
	
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include "utils.hpp"

//All the strings, except path, are in lower case after loading.
class SettingsLoader  
{
	private:
		std::vector< std::string > pathPlaces;
		std::string credentialCell;
		std::string totalCell;
		std::vector< std::string > specialSheetCell;
		std::vector< std::string > monthesFolders;
		void loadPathPlaces(const std::string& line);
		void loadCredentialCell(const std::string& line);
		void loadTotalCell(const std::string& line);
		void loadSpecialSheetCell(const std::string& line);
		void loadMonthesFolder(const std::string& line);
		void tolower(std::string& s);

	public:
		const std::vector<std::string> getPathPlaces() const{return pathPlaces;};
		const std::string getCredentialCell() const {return credentialCell;};
		const std::string getTotalCell() const {return totalCell;};
		const std::vector<std::string> getSpecialSheetCells() const {return specialSheetCell;};
		const std::vector<std::string> getMonthesFolders() const {return monthesFolders;};

		SettingsLoader();
		~SettingsLoader();

};

#endif