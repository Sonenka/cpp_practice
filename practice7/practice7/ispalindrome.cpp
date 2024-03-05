#include "ispalindrome.hpp"
#include <cctype>
#include <iostream>
#include <string>

bool isPalindrome(std::string str) {
	std::string::iterator left = str.begin();
	std::string::iterator right = str.end() - 1;

	while (left < right) {
		if (std::tolower(*left) != std::tolower(*right)) {
			return false;
		}

		left++;
		right--;
	}

	return true;
}