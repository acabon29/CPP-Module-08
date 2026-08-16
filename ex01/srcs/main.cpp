
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void) {

	std::srand(std::time(0));

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;

		Span big(100000);
		std::vector<int> vec;
		for (int i = 0; i < 100000; ++i)
			vec.push_back(rand());
		big.addNumber(vec.begin(), vec.end());

		std::cout << "Shortest span : " << big.shortestSpan() << std::endl;
		std::cout << "Longest span : " << big.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}

	return 0;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
