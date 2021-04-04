#include "SettingsLoader.hpp"  
	
std::string SettingsLoader::monthFolderSettingsName = "monthFolder.csv";

SettingsLoader::SettingsLoader()
{
    std::string line;
	std::ifstream settingsFile("settings.csv");
    if(settingsFile.is_open()){
        std::getline(settingsFile,line);
        loadCredentialCell(line);
        std::getline(settingsFile,line);
        loadTotalCell(line);
        std::getline(settingsFile,line);
        loadSpecialSheetCell(line);
        std::getline(settingsFile,line);
        loadDateCell(line);
        settingsFile.close();
    }

    std::ifstream settingsMonthFolder(monthFolderSettingsName);
    if(settingsMonthFolder.is_open()){
        std::getline(settingsMonthFolder,line);
        loadMonthFolder(line);
        settingsMonthFolder.close();
    }
}

void SettingsLoader::saveMonthFolder(const std::string& line){
    std::ofstream settingsMonthFolder(monthFolderSettingsName, std::ios::out);//std::ios::trunc
    if(settingsMonthFolder.is_open()){
        settingsMonthFolder << line;
        settingsMonthFolder.close();
    }
}

void SettingsLoader::loadFoldersPlaces(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    value.clear();
    while(utils::lineParser(line, value, i)){
        //If value is not empyt push back the new path
        if(value != ""){
            foldersPlaces.push_back(value);
            value.clear();
        }
    }
    foldersPlaces.push_back(value);
}

void SettingsLoader::loadCredentialCell(const std::string& line){
    int i=0;
    std::string value, sheet, cell;
    utils::lineParser(line, value, i);
    utils::lineParser(line, sheet, i);
    utils::lineParser(line, cell, i);
    utils::tolower(cell);
    credentialCell.push_back(sheet);
    credentialCell.push_back(cell);
}

void SettingsLoader::loadDateCell(const std::string& line){
    int i=0;
    std::string value, sheet, cell;
    utils::lineParser(line, value, i);
    utils::lineParser(line, sheet, i);
    utils::lineParser(line, cell, i);
    utils::tolower(cell);
    dateCell.push_back(sheet);
    dateCell.push_back(cell);
}

void SettingsLoader::loadTotalCell(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    utils::lineParser(line, totalCell, i);
    utils::tolower(totalCell);
}

void SettingsLoader::loadSpecialSheetCell(const std::string& line){
    int i=0;
    std::string value, sheet, cell;
    utils::lineParser(line, value, i);
    utils::lineParser(line, sheet, i);
    utils::lineParser(line, cell, i);
    utils::tolower(cell);
    specialSheetCell.push_back(sheet);
    specialSheetCell.push_back(cell);
}

void SettingsLoader::loadMonthesFolder(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    value.clear();
    while(utils::lineParser(line, value, i)){
        //If value is not empyt push back the new month
        if(value != ""){
            monthesFolders.push_back(value);
            value.clear();
        }
    }
}

void SettingsLoader::loadWorkSheets(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    value.clear();
    while(utils::lineParser(line, value, i)){
        //If value is not empyt push back the new month
        if(value != ""){
            workSheets.push_back(value);
            value.clear();
        }
    }
}

void SettingsLoader::loadRootDir(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    utils::lineParser(line, rootDir, i);
}

void SettingsLoader::loadMonthFolder(const std::string& line){
    monthFolder = line;
}

SettingsLoader::~SettingsLoader()
{
	
}