#include "Utils.hpp"  
	
bool utils::lineParser(const std::string& line, std::string& value, int& i, char delimiter){
    while(line[i] != delimiter && i<line.size()){
        value += line[i];
        ++i;
    }
    ++i;
    return i < line.size();
}

int utils::charExcelToNumber(const std::string& col){
    return col[0]-'a';
}