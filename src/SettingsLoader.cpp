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
        settingsFile.close();
    }
}

void SettingsLoader::loadPathPlaces(const std::string& line){
    int i=0;
    std::string value;
    lineParser(line, value, i);
    value.clear();
    while(lineParser(line, value, i)){
        pathPlaces.push_back(value);
        value.clear();
    }
    pathPlaces.push_back(value);
}

void SettingsLoader::loadCredentialCell(const std::string& line){
    int i=0;
    std::string value;
    lineParser(line, value, i);
    lineParser(line, credentialCell, i);
}

void SettingsLoader::loadTotalCell(const std::string& line){
    int i=0;
    std::string value;
    lineParser(line, value, i);
    lineParser(line, totalCell, i);
}

void SettingsLoader::loadSpecialSheetCell(const std::string& line){
    int i=0;
    std::string value, sheet, cell;
    lineParser(line, value, i);
    lineParser(line, sheet, i);
    lineParser(line, cell, i);
    specialSheetCell.push_back(sheet);
    specialSheetCell.push_back(cell);
}

SettingsLoader::~SettingsLoader()
{
	
}

bool SettingsLoader::lineParser(const std::string& line, std::string& value, int& i, char delimiter){
    while(line[i] != delimiter && i<line.size()){
        value += line[i];
        ++i;
    }
    ++i;
    return i < line.size();
}