#ifndef SPIELER_H
#define SPIELER_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

class Spieler {
public:
	const std::vector<Card>& getCards() const;
	void addCard(const Card& card);
	const int getCardsValue() const;
private:
	std::vector<Card> cards;
};



#endif