#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span &src) {
	*this = src;
}

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		this->_maxSize = src._maxSize;
		this->_numbers = src._numbers;
	}
	return *this;
}

void	Span::addNumber(int n) {
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.push_back(n);
}

int	Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::vector<int> tmp(_numbers);
	std::sort(tmp.begin(), tmp.end());

	int minSpan = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); ++i) {
		int span = tmp[i] - tmp[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int	Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}

