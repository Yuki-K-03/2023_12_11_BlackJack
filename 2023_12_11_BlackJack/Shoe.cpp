#include <iostream>
#include <ctime>
#include "Shoe.h"
using namespace std;


// コンストラクタ
Shoe::Shoe() {
	_cardNum = CARD_MAX - 1;

	int num = 0;
	int suit = 0;

	for (int i = 0; i < CARD_MAX; i++) {
		num = i % NUMBER_MAX + 1;
		suit = i / NUMBER_MAX + 1;
		_cardShoe[i].SetCard(num, suit);
	}
}

Shoe::~Shoe() {

}

bool Shoe::takeCard(Card &card) {
	if (_cardShoe[_cardNum].GetNum() < 0 && _cardShoe[_cardNum].GetSuit() < 0) {
		return false;
	}

	card = _cardShoe[_cardNum];
	_cardShoe[_cardNum].SetCard(-1, -1);
 	_cardNum--;

	return true;
}

//シャッフル（フィッシャーイェーツ）
void Shoe::_shuffle()
{
	srand((unsigned int)time(NULL));

	for (int i = _cardNum + 1; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}
