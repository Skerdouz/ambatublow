#ifndef KARTENDECK_H
#define KARTENDECK_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

class Kartendeck {
public:
	Kartendeck();
	void shuffle();
	Card drawCard();
	int getRemainingCards() const;
	bool isEmpty() const;
	
private:
	std::vector<Card> cards;
};



#endif