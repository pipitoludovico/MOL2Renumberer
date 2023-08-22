#include "Common.h"

std::vector<std::string> Split(const std::string& str, char delimiter, int position) {
	std::vector<std::string> tokens;
	std::string token;
	std::stringstream ss(str);

	while (std::getline(ss, token, delimiter))
	{
		if (!token.empty())
		{
			tokens.push_back(token);
		}
	}

	if (position >= 0 && position < tokens.size())
	{
		return { tokens[position] };
	}
	else
	{
		return tokens;
	}
}

std::string GetSplitElement(const std::string& str, char delimiter, int index) {
	std::vector<std::string> tokens;
	std::regex regex(std::string(1, delimiter) + "+");
	std::sregex_token_iterator it(str.begin(), str.end(), regex, -1);
	std::sregex_token_iterator end;

	while (it != end) {
		tokens.push_back(*it);
		++it;
	}

	if (index >= 0 && index < tokens.size()) {
		return tokens[index];
	}
	else {
		return "";  // Restituisci una stringa vuota se l'indice non è valido
	}
}


std::vector<std::vector<char>> Split2(const std::string& str, char delimiter, int pos) {
	std::vector<std::vector<char>> wordList;
	std::vector<char> word;
	for (char letter : str)
	{
		if (letter == delimiter)
		{
			wordList.emplace_back(word);
			word.clear();
		}
		else
		{
			word.emplace_back(letter);
		}
	}
	wordList.emplace_back(word);

	if (pos != -1 && pos < wordList.size()) {
		std::vector<std::vector<char>> singleWord;
		singleWord.emplace_back(wordList[pos]);
		return singleWord;
	}
	else
	{
		return wordList;
	}
}