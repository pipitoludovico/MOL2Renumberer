#include "Common.h"
#ifndef _MOL2READER
#define _MOL2READER

struct MOL2READER
{
	std::vector<std::string> atomNewCount;
	MOL2READER(std::fstream& file);

	void CreateAtomCounters(std::string& line, std::map<char, int>& map, std::vector<std::string>& countVector);
	std::vector<std::string> GetNewAtomList();
	void ChangeAtomsInMOL2(const std::string& newName);
	
};

#endif
