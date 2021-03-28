#ifndef SETTINGSLOADER_H
#define SETTINGSLOADER_H
#pragma once
	
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

class SettingsLoader  
{
	private:
		std::vector< std::string > pathPlaces;
		std::string credentialCell;
		std::string totalCell;
		std::vector< std::string > specialSheetCell;
		//Return false if endline
		bool lineParser(const std::string& line, std::string& value, int& i, char delimiter=';');
		void loadPathPlaces(const std::string& line);
		void loadCredentialCell(const std::string& line);
		void loadTotalCell(const std::string& line);
		void loadSpecialSheetCell(const std::string& line);

	public:
		const std::vector<std::string>& getPathPlaces() const {return pathPlaces;};
		const std::string& getCredentialCell() const {return credentialCell;};
		const std::string& getTotalCell() const {return totalCell;};
		const std::vector<std::string>& getSpecialSheetCells() const {return specialSheetCell;};

		SettingsLoader();
		~SettingsLoader();

};

#endif