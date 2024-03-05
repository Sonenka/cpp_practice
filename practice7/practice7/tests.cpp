#include "ispalindrome.hpp"
#include "sort.hpp"
#include "tests.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

void isPalindrome_test() {
	std::cout << "ISPALINDROME_TEST" << std::endl;
	std::string str1 = "loL";
	std::string str2 = "ne loL";

	std::cout << "'" << str1 << "' is " << (isPalindrome(str1) ? "palindrome" : "not palindrome") << std::endl;
	std::cout << "'" << str2 << "' is " << (isPalindrome(str2) ? "palindrome" : "not palindrome") << std::endl;
	
	std::cout << std::endl;
}

void sort_test() {
	std::cout << "SORT_TEST" << std::endl;

	std::string initial_string = "C++ is a very performant language.";
	std::cout << initial_string << std::endl;

	std::vector<std::string> words = sort(split(initial_string));

	for (size_t i = 0; i < words.size(); i++) {
		std::cout << words[i] << " ";
	}

	std::cout << std::endl;

}

void test_all() {
	isPalindrome_test();
	sort_test();
}