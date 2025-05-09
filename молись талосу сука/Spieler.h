#ifndef SPIELER_H
#define SPIELER_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

class Spieler {
public:
	const std::vector<Card>& getCards() const;
	const std::string& getName() const;
	void setName(const std::string& name);

	void addCard(const Card& card);
	const int getCardsValue() const;
private:
	std::string name;
	std::vector<Card> cards;
};



#endif