#include "sort.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> sort(std::vector<std::string> initial_words) {
	std::vector<std::string> words = initial_words;
	for (size_t i = 0; i < words.size() - 1; i++) {
		for (size_t j = 0; j < words.size() - 1 - i; j++) {
			if (words[j].length() > words[j + 1].length()) {
				std::swap(words[j], words[j + 1]);
			}
		}
	}

	return words;
}

std::vector<std::string> split(std::string str) {
	std::string word;
	std::vector<std::string> words;
	std::string::iterator start = str.begin();

	while (start != str.end()) {
		while (std::isspace(*start)) {
			words.push_back(word);
			word = "";
			start++;
		}

		word += *start;
		start++;
	}

	words.push_back(word);

	return words;
}