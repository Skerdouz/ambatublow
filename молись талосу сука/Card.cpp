#include "Card.h"


const std::string& Card::getSymbol() const {
	return (symbol);
}

void Card::setSymbol(const std::string& symbol) {
	Card::symbol = symbol;
}

const std::string& Card::getValue() const {
	return (value);
}

void Card::setValue(const std::string& value) {
	Card::value = value;
}