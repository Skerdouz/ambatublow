#include "Kartendeck.h"

Kartendeck::Kartendeck() {
	// init the 52 cards KARTENDECK 
	const std::string symbols[] = { "Hearts", "Diamond", "Clubs", "Spades" };
	const std::string values[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

	cards.clear();
	for (const auto& symbol : symbols) {
		for (const auto& value : values) {
			Card card;
			card.setSymbol(symbol);
			card.setValue(value);
			cards.push_back(card);
		}
	}
}

void Kartendeck::shuffle() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
}

Card Kartendeck::drawCard() {
	if (cards.empty()) {
		throw std::out_of_range("No more cards in the deck");
	}
	Card card = cards.back();
	cards.pop_back();
	return (card);
}

bool Kartendeck::isEmpty() const {
	return (cards.empty());
}

const std::vector<Card>& Kartendeck::getCards() const {
	return (cards);
}