#include <iostream>
#include "Card.h"


bool Card::operator==(const Card other) {
	if (_cardNum == other._cardNum && _cardSuit == other._cardSuit) {
		return true;
	}
	else {
		return false;
	}
}

Card::Card() {
	_cardNum = 0;
	_cardSuit = 0;
}

const int Card::GetNum() const {
	return _cardNum;
}

const int Card::GetSuit() const {
	return _cardSuit;
}

void Card::SetCard(int num, int suit) {
	_cardNum = num;
	_cardSuit = suit;
}