/*
* Author: CS
* Date: 2022/03/09
*
* (Not noteworthy)
*/

#include <iostream>
#include <list>
#include <vector>
#include <exception>
#include <iomanip>
#include <algorithm>

std::list<int> li{ 2,5,3,7,1,9 };

void func(std::list<int> li) {
	// create vector<double> from list<int>
	std::vector<double> vect;
	auto iter = li.begin();
	auto end = li.end();
	while (iter != end) {
		vect.push_back(*iter);
		++iter;
	}

	// check vector
	if (vect.size() < 0)
		throw std::exception("Invalid vector");

	auto iter2 = li.begin();
	bool check{ true };
	for (int entry : vect) {
		if (entry != double(* iter2))
			check = false;
		++iter2;
	}

	std::cout << "The copy was compete and correct: ";
	std::cout << std::boolalpha << check << std::endl << std::endl;


	// sort and print
	std::cout << "The elements in order of increasing value:\n";
	std::sort(vect.begin(), vect.end());
	for (auto temp : vect)
		std::cout << temp << ' ';
	std::cout << std::endl;
}

int main() {
	func(li);
}