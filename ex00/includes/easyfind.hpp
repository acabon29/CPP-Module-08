#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
// marche sans stdexcept mais c'est mieux de l'inclure en fonction de la norme C++ utilisée
#include <stdexcept> // pour std::invalid_argument
#include <algorithm> // pour std::find


template <typename T>
typename T::iterator easyfind(T &intContainer, int value)
{
	typename T::iterator it = std::find(intContainer.begin(), intContainer.end(), value);

	if (it == intContainer.end())
		throw std::invalid_argument("Value not found.");
	// unsigned int position = std::distance(intContainer.begin(), it);
	// std::cout << value << " was found at the position " << position << std::endl;
	return it;
}




