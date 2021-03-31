#include "SettingsLoader.hpp"  
	
SettingsLoader::SettingsLoader()
{
    std::string line;
	std::ifstream settingsFile("settings.csv");
    if(settingsFile.is_open()){
        std::getline(settingsFile,line);
        loadPathPlaces(line);
        std::getline(settingsFile,line);
        loadCredentialCell(line);
        std::getline(settingsFile,line);
        loadTotalCell(line);
        std::getline(settingsFile,line);
        loadSpecialSheetCell(line);
        std::getline(settingsFile,line);

        //loadMonthesFolder(line);
        settingsFile.close();
    }
}

void SettingsLoader::tolower(std::string& s){
    for(int i=0; i<s.length(); ++i){
        if(s[i]>='A' && s[i]<='Z')
            s[i] -= ('Z'-'z');
    }
}

void SettingsLoader::loadPathPlaces(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    value.clear();
    while(utils::lineParser(line, value, i)){
        //If value is not empyt push back the new path
        if(value != ""){
            pathPlaces.push_back(value);
            value.clear();
        }
    }
    pathPlaces.push_back(value);
}

void SettingsLoader::loadCredentialCell(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    utils::lineParser(line, credentialCell, i);
    tolower(credentialCell);
}

void SettingsLoader::loadTotalCell(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    utils::lineParser(line, totalCell, i);
    tolower(totalCell);
}

void SettingsLoader::loadSpecialSheetCell(const std::string& line){
    int i=0;
    std::string value, sheet, cell;
    utils::lineParser(line, value, i);
    utils::lineParser(line, sheet, i);
    utils::lineParser(line, cell, i);
    tolower(sheet);
    tolower(cell);
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

void SettingsLoader::loadRootDir(const std::string& line){
    int i=0;
    std::string value;
    utils::lineParser(line, value, i);
    utils::lineParser(line, rootDir, i);
}

SettingsLoader::~SettingsLoader()
{
	
}