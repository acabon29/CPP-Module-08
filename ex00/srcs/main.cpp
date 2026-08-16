#include "easyfind.hpp"

#include "easyfind.hpp"

int main(void) {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found in vector : " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(2);
	lst.push_back(4);
	lst.push_back(6);
	lst.push_back(8);
	lst.push_back(10);

	try {
		std::list<int>::iterator it = easyfind(lst, 6);
		std::cout << "Found in list : " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
