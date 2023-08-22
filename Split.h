#ifndef _SPLIT
#define _SPLIT


std::vector<std::string> Split(const std::string& str, char delimiter, int position = -1);

std::string GetSplitElement(const std::string& str, char delimiter, int index = -1);

std::vector<std::vector<char>> Split2(const std::string& str, char delimiter, int pos = -1);

#endif