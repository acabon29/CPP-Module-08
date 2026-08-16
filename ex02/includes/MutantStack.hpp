
#pragma once

#include <stack>

// stack est un adaptateur de conteneur 
// fournit une interface sur un conteneur sous-jacent (std::)
// deque peut être remplacé par d'autres conteneurs tels que std::vector ou std::list.
template <typename T>
class MutantStack : public std::stack<T> {
public:
	// container_type est un typedef standard exposé publiquement par std::stack
	// (il pointe vers le type du container sous-jacent, ici std::deque<T> par défaut).
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

	// iterator : permet de lire et modifier l'élément pointé. *it = 42; fonctionne.
	// const_iterator : permet seulement de lire l'élément pointé. *it = 42; ne compile pas — c'est un accès en lecture seule.
	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;
};

#include "MutantStack.tpp"