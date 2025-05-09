// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Kartendeck.h"
#include "Spieler.h"

void printDeck(const Kartendeck& deck) {
	for (const auto& card : deck.getCards()) {
		std::cout << card.getValue() << " of " << card.getSymbol() << std::endl;
	}
}

void hitCard(Kartendeck* deck, Spieler* player) {
	std::cout << "You are drawing a card..." << std::endl << std::endl;;
	try {
		Card drawnCard = deck->drawCard();
		player->addCard(drawnCard);
		std::cout << "You drew: " << drawnCard.getValue() << " of " << drawnCard.getSymbol() << std::endl;
		std::cout << "You're at: " << player->getCardsValue() << std::endl << std::endl;;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

void game_handle(Kartendeck* deck, Spieler* player) {
	bool inGame = true;

	while (inGame) {
		if (deck->getCards().size() < 15) { // recreate deck if	less than 15 cards left
			std::cout << "Not enough cards in the deck, shuffling..." << std::endl;
			*deck = Kartendeck();
			deck->shuffle();
			return;
		}

		while (player->getCards().size() < 2) {
			hitCard(deck, player);
		}

		char choice;

		std::cout << "Would you like to: [H]it or [S]tand ?" << std::endl;
		std::cin >> choice;

		if (choice == 'H' || choice == 'h') {
			hitCard(deck, player);
			if (player->getCardsValue() >= 21) {
				if (player->getCardsValue() == 21)
					std::cout << "You got a BLACKJACK!" << std::endl;
				else 
					std::cout << "You busted!" << std::endl;
				return;
			}
		}
		else if (choice == 'S' || choice == 's') {
			std::cout << "You are standing..." << std::endl;
			return;
		}
		else
			std::cout << "Invalid choice, choose [H]it or [S]tand." << std::endl;
	}
}

int main() {
	Kartendeck deck;
	Spieler player;
	Spieler dealer;

	deck.shuffle();

	game_handle(&deck, &player);
	std::cout << "Your final value: " << player.getCardsValue() << std::endl;
	return (0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
