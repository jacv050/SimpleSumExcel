#include "Utils.hpp"  
	
bool utils::lineParser(const std::string& line, std::string& value, int& i, char delimiter){
    while(line[i] != delimiter && i<line.size()){
        value += line[i];
        ++i;
    }
    ++i;
    return i < line.size();
}

bool utils::lineParser(const std::wstring& line, std::wstring& value, int& i, char delimiter){
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

void utils::tolower(std::string& s){
    for(int i=0; i<s.length(); ++i){
        if(s[i]>='A' && s[i]<='Z')
            s[i] -= ('Z'-'z');
    }
}

void utils::splitCell(const std::string& cell, std::string& row, std::string& col){
    int i=0;
    while(i<cell.size() && cell[i] >= 'a' && cell[i] <= 'z'){
        col.append(1,cell[i]);
        ++i;
    }
    while(i<cell.size()){
        row.append(1,cell[i]);
        ++i;
    }
}

void utils::excelToIndex(const std::string& cell, int& row_i, int& col_i){
    std::string row_s, col_s;
    splitCell(cell, row_s, col_s);
    row_i = atoi(row_s.c_str())-1; col_i = charExcelToNumber(col_s);
}