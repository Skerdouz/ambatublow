// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Kartendeck.h"
#include "Spieler.h"

void printDeck(const Kartendeck& deck) {
	for (const auto& card : deck.getCards()) {
		std::cout << card.getValue() << " of " << card.getSymbol() << std::endl;
	}
}

void hitCard(Kartendeck* deck, Spieler* spieler) {
	try {
		Card drawnCard = deck->drawCard();
		spieler->addCard(drawnCard);
		if (spieler->getName() == "Dealer" && spieler->getCards().size() == 2)
			std::cout << "Dealer drew a card" << std::endl << std::endl;
		else {
			std::cout << spieler->getName() << " drew: " << drawnCard.getValue() << " of " << drawnCard.getSymbol() << std::endl;
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

void printValues(const Spieler* player, const Spieler* dealer, const bool final) {
	if (final)
		std::cout << std::endl << "Player: " << player->getCardsValue() << " | Dealer: " << dealer->getCardsValue() << std::endl;
	else
		std::cout << std::endl << "Player: " << player->getCardsValue() << " | Dealer: " << dealer->getCards().front().getValue() << std::endl;
}

void game_handle(Kartendeck* deck, Spieler* player, Spieler* dealer) {
	// TODO: add dealer logic and SPLIT option
	bool inGame = true;

	while (inGame) {
		if (deck->getCards().size() < 15) { // recreate deck if	less than 15 cards left
			std::cout << "Not enough cards in the deck, shuffling..." << std::endl;
			*deck = Kartendeck();
			deck->shuffle();
			return;
		}

		if (player->getCards().size() < 2) {
			hitCard(deck, player);
			hitCard(deck, dealer);
			hitCard(deck, player);
			hitCard(deck, dealer);
			printValues(player, dealer, false);
		}

		if (dealer->getCardsValue() == 21) {
			std::cout << "Dealer got a BLACKJACK!" << std::endl;
			return;
		}

		char choice;

		std::cout << "Would you like to: [H]it or [S]tand ?" << std::endl;
		std::cin >> choice;

		if (choice == 'H' || choice == 'h') {
			hitCard(deck, player);
			printValues(player, dealer, false);
			if (player->getCardsValue() >= 21) {
				if (player->getCardsValue() == 21)
					std::cout << "You got a BLACKJACK!" << std::endl;
				else 
					std::cout << "You busted!" << std::endl;
				return;
			}
		}
		else if (choice == 'S' || choice == 's') {
			std::cout << std::endl << "You are standing..." << std::endl;
			while (dealer->getCardsValue() < 17) {
				hitCard(deck, dealer);
				printValues(player, dealer, true);
				if (dealer->getCardsValue() >= 21) {
					if (dealer->getCardsValue() == 21)
						std::cout << "Dealer got a BLACKJACK!" << std::endl;
					else
						std::cout << "Dealer busted!" << std::endl;
					return;
				}
			}
			printValues(player, dealer, true);
			if (dealer->getCardsValue() > player->getCardsValue())
				std::cout << "Dealer won." << std::endl;
			else if (dealer->getCardsValue() == player->getCardsValue())
				std::cout << "It's a tie." << std::endl;
			else
				std::cout << "Player won!" << std::endl;
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
	dealer.setName("Dealer");
	player.setName("Player");

	deck.shuffle();

	game_handle(&deck, &player, &dealer);
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
