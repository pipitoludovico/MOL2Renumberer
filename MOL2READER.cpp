#include "MOL2READER.h"

MOL2READER::MOL2READER(std::fstream& file)
{
    std::vector<std::string> atomNewCount;
    std::map<char, int> idx_map;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            CreateAtomCounters(line, idx_map, this->atomNewCount);
        }
        /*for (auto const& val : idx_map) {
            std::cout << val.first << ":" << val.second << "\n";
        }
        for (std::string x : atomNewCount) {
            std::cout << x << "\n";
        }*/
    }
}


void MOL2READER::CreateAtomCounters(std::string& line, std::map<char, int>& map, std::vector<std::string>& countVector){
    std::set<char> atomsInitials = { 'C', 'N', 'O', 'S', 'F', 'H', 'B', 'P', 'I' };
 
    std::map<char, int>::iterator it;


    if (line.length() >= 71){
        std::string atomNameNum= line.substr(7, 7);
        char atomId = atomNameNum[1];
            if (atomId != ' '){
                if (std::find(atomsInitials.begin(), atomsInitials.end(), atomId) != atomsInitials.end()){
                    if (map.find(atomId) == map.end()) {
                        map[atomId] = 1;
                        countVector.push_back(atomId + std::to_string(map[atomId]));
                    }
                    else {
                        map[atomId]++;
                        countVector.push_back(atomId + std::to_string(map[atomId]));}
                    }
            }
    }
}

std::vector<std::string> MOL2READER::GetNewAtomList(){
    return this->atomNewCount;
}


void MOL2READER::ChangeAtomsInMOL2(const std::string& filePath)
{
    std::vector<std::string> newList = GetNewAtomList();
    size_t namePosition = filePath.find_last_of(".");
    std::string newFileName = filePath.substr(0, namePosition) + "_renumbered.mol2";

    std::fstream newFile(newFileName, std::ios::out);
    std::fstream oldMOL2File(filePath, std::ios::in);

    int idx = 0;
    if (!newFile.is_open() || !oldMOL2File.is_open()) {
        std::cerr << "Errore nell'apertura dei file." << std::endl;
        return;
    }

    if (oldMOL2File.is_open()) {
        std::string oldLine;
        while (std::getline(oldMOL2File, oldLine)) {
            if (oldLine.length() >= 71) {
                newFile << oldLine.substr(0, 7) << " " << newList[idx] << oldLine.substr(9, -1) << '\n';
                idx++;
            }
            else {
                newFile << oldLine << "\n";
            }
        }
    }
    newFile.close();
    oldMOL2File.close();
}