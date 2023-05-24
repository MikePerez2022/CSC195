using namespace std;

#include<iostream>
#include "List.h"


int main() {

	std::cout << "Hello World!\n";

	std::cout << "list\n";

	nc::list<int> numbers{ 12, 78, 12, 34, 9 };
	numbers.push_back(10);
	numbers.push_front(8);
	numbers.write(std::cout);
	std::cout << "copy\n";
	nc::list<int> copy;
	copy = numbers;
	copy.pop_front();
	copy.pop_back();
	copy.pop_back();
	copy.write(std::cout);
	std::cout << "remove\n";
	copy.remove(12);
	copy.write(std::cout);
	std::cout << "resize\n";
	//copy.resize(10, 99); // ************** resize is no longer required
	copy.write(std::cout);
	cout << "Resize method is no longer a requirement \n";
	std::cout << "reverse\n";
	numbers.reverse();
	numbers.write(std::cout);
	std::cout << "front: " << numbers.front() << std::endl;
	std::cout << "back: " << numbers.back() << std::endl;
	std::cout << "size: " << numbers.size() << std::endl;
	std::cout << "empty: " << numbers.empty() << std::endl;
	numbers.~list();
	copy.~list();
	
}