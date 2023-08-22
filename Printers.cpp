#include "Printers.h"

std::ostream& operator<<(std::ostream& stream, const std::vector<char>& charVector) {
    for (char c : charVector) {
        stream << c;
    }
    std::cout << "\n";
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const std::vector<std::string>& wordList) {
    for (const std::string& word : wordList) {
        for (char letter : word) {
            stream << letter;
        }
        stream << std::endl; // Aggiungi una nuova riga dopo ogni parola
    }
    return stream;
}