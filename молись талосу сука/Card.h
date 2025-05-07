#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
	const std::string& getColor() const;
	const std::string& getSymbol() const;
	const std::string& getValue() const;
	void				setColor(const std::string& color);
	void				setSymbol(const std::string& symbol);
	void				setValue(const std::string& value);
private:
	std::string	color;
	std::string	symbol;
	std::string	value;
};

#endif