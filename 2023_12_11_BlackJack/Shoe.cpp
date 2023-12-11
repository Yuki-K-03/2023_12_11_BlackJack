#include <iostream>
#include <ctime>
#include "Shoe.h"
using namespace std;


// �R���X�g���N�^
Shoe::Shoe() {
	_cardNum = CARD_MAX - 1;

	int num = 0;
	int suit = 0;

	/*for (int i = 0; i < _cardNum; i++) {
		_cardShoe[i] = i;
	}*/

	for (int i = 0; i < CARD_MAX; i++) {
		num = i % NUMBER_MAX + 1;
		suit = i / NUMBER_MAX;
		_cardShoe[i].SetCard(num, suit);
	}
}

Shoe::~Shoe() {

}

bool Shoe::takeCard(Card &card) {
	card = _cardShoe[_cardNum];
	/*printf("%d num:%d", _cardShoe[_cardNum].GetNum(), _cardNum);

	printf("\n\n");
	for (int i = 0; i < _cardNum; i++) {
		printf("%d ", _cardShoe[i].GetNum());
	}
	printf("\n\n");*/

	if (card.GetNum() <= 0) {
		return false;
	}

	_cardShoe[_cardNum].SetCard(-1, -1);
 	_cardNum--;
	//printf("\n%d: %d\n", card._cardNum, card._cardSuit);

	return true;
}

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
void Shoe::_shuffle()
{
	srand((unsigned int)time(NULL));

	for (int i = _cardNum + 1; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}
