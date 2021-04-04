#ifndef SETTINGSLOADER_H
#define SETTINGSLOADER_H
#pragma once
	
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "utils.hpp"
#include "boost/filesystem.hpp"

//All the strings, except path, are in lower case after loading.
class SettingsLoader  
{
	private:
		std::vector< std::string > foldersPlaces;
		std::vector< std::string > credentialCell;
		std::string totalCell;
		std::string rootDir;
		std::vector< std::string > specialSheetCell;
		std::vector< std::string > monthesFolders;
		std::vector< std::string > workSheets;
		std::vector< std::string > dateCell;
		std::string monthFolder;
		void loadFoldersPlaces(const std::string& line);
		void loadCredentialCell(const std::string& line);
		void loadTotalCell(const std::string& line);
		void loadSpecialSheetCell(const std::string& line);
		void loadMonthesFolder(const std::string& line);
		void loadRootDir(const std::string& line);
		void loadWorkSheets(const std::string& line);
		void loadMonthFolder(const std::string& line);
		void loadDateCell(const std::string& line);
		static std::string monthFolderSettingsName;

	public:
		const std::vector<std::string> getFoldersPlaces() const{return foldersPlaces;};
		const std::vector<std::string> getCredentialCell() const {return credentialCell;};
		const std::string getTotalCell() const {return totalCell;};
		const std::vector<std::string> getSpecialSheetCells() const {return specialSheetCell;};
		const std::vector<std::string> getMonthesFolders() const {return monthesFolders;};
		const std::string getRootDir() const {return rootDir;};
		const std::vector<std::string> getWorkSheets() const {return workSheets;};
		const std::vector<std::string> getDateCell() const {return dateCell;};
		const std::string getMonthFolder() const {return monthFolder;};
		void saveMonthFolder(const std::string& line);

		SettingsLoader();
		~SettingsLoader();

};

#endif