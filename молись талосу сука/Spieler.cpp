#include "Spieler.h"
#include <string>

const std::vector<Card>& Spieler::getCards() const {
	return (cards);
}

void Spieler::addCard(const Card& card) {
    cards.push_back(card);
}

const int Spieler::getCardsValue() const {
	int aceCount= 0;
	int value = 0;

	for (const auto& card : cards) {
		if (card.getValue() == "King" || card.getValue() == "Queen" || card.getValue() == "Jack") {
			value += 10;
		}
		else if (card.getValue() == "Ace") { // Ace can be 1 or 11 will be handled after loop
			aceCount += 1;
			if (value < (value + 11))
				value += 11;
			else
				value += 1;
		}
		else {
			value += std::stoi(card.getValue());
		}
	}
	if (value > 21 && aceCount) { // Ace goes from 11 to 1 if value > 21
		for (int i = 0; i < aceCount; ++i) {
			if (value > 21)
				value -= 10;
		}
	}
	return value;
}