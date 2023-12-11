#include <iostream>
#include "Player.h"
#include "Shoe.h"
using namespace std;


Player::Player(const char* name) : Person(name) {

}

Player::~Player() {

}

//�Q�[�����s
void Player::PlayBase(Shoe& shoe) {

	//����
	char str[HAND_SIZE] = {" "}; //������^
	//�o�[�X�g����܂Ń��[�v����
	do {
		cout << "hit or stand >> ";

		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			hit(shoe);

			//��D�̕\��
			cout << "====================" << endl;
			cout << "player" << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			break;
		}
	} while (calcScore());
}
