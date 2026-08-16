#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {

	private:

		unsigned int		_maxSize;
		std::vector<int>	_numbers;
		Span();

	public:

		Span(unsigned int N);
		~Span();
		Span(const Span &src);
		Span &operator=(const Span &src);

		void	addNumber(int n);

		template <typename Iterator>

		// les fonctions membres templates doivent être définies dans le header
		// le compilateur doit générer le code pour chaque type d'itérateur utilisé lors de l'appel de la fonction
		// on peut aussi utiliser un .tpp mais c'est moins courant
		void	addNumber(Iterator begin, Iterator end) {
			// calcule le nombre d'éléments entre begin et end. Le type de retour dépend du type d'itérateur
			// ce n'est pas toujours int, c'est en général ptrdiff_t
			typename std::iterator_traits<Iterator>::difference_type dist = std::distance(begin, end);

			 // savoir si begin est situé après end
			if (dist < 0)
				throw std::invalid_argument("Invalid iterator range");

			if (static_cast<unsigned int>(dist) + _numbers.size() > _maxSize)
				throw std::runtime_error("Span is full");
			_numbers.insert(_numbers.end(), begin, end);
		}

		int		shortestSpan() const;

		int		longestSpan() const;
};