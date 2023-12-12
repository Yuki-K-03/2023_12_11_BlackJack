#pragma once

extern const int NUMBER_MAX;
extern const char* CARD_NUMBER[];
extern const char* CARD_SUIT[];


class Card
{
protected :
	int _cardNum;
	int _cardSuit;

public :
	bool operator==(const Card other);
	Card();
	void SetCard(int num, int suit);
	const int GetNum()  const;
	const int GetSuit()  const;
};