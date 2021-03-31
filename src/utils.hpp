#ifndef UTILS_H
#define UTILS_H
#pragma once
	
#include <string>

namespace utils{
	//Return false if endline
	bool lineParser(const std::string& line, std::string& value, int& i, char delimiter=';');
	//Limited to a-z
	int charExcelToNumber(const std::string& col);
}

#endif