#ifndef UTILS_H
#define UTILS_H
#pragma once
	
#include <string>

namespace utils{
	//Return false if endline
	bool lineParser(const std::string& line, std::string& value, int& i, char delimiter=';');
	bool lineParser(const std::wstring& line, std::wstring& value, int& i, char delimiter=';');
	//Limited to a-z
	int charExcelToNumber(const std::string& col);
	void tolower(std::string& s);
	void excelToIndex(const std::string& cell, int& row_i, int& col_i);
	void splitCell(const std::string& cell, std::string& row, std::string& col);
}

#endif