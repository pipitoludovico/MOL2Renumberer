#include "Common.h"
#include "MOL2READER.h"

int main(int argc, char* argv[]) {
    std::string filePath = argv[1];

    std::fstream file(filePath, std::ios::in);

    MOL2READER reader(file);
    reader.ChangeAtomsInMOL2(filePath);

}
