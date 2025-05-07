#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
	const std::string& getSymbol() const;
	const std::string& getValue() const;
	void				setSymbol(const std::string& symbol);
	void				setValue(const std::string& value);
private:
	std::string	symbol;
	std::string	value;
};

#endif