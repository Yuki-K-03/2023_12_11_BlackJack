#include <iostream>
#include <ctime>
#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"
using namespace std;


const int NUMBER_MAX = 13;
const char* CARD_NUMBER[] = { "Joker", " A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K" };
const char* CARD_SUIT[] = { "  heart", "diamond", "  spade", "   club" };


void ShowHand(Person& person) {
	person.showName();
	person.showHand();
	person.showScore();
}

static void showResult(Player& player, Dealer& dealer)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	ShowHand(dealer);
	ShowHand(player);

	if (player.calcScore() > dealer.calcScore()) {
		cout << "Player Win!" << endl;
	}
	else if (player.calcScore() < dealer.calcScore()) {
		cout << "Player Lose" << endl;
	}
	else {
		cout << "Push" << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	Player p("Player");
	Dealer d;
	Shoe shoe;
	shoe._shuffle();

	printf("======================\n");
	d.hit(shoe);
	ShowHand(d);
	d.hit(shoe);
	printf("======================\n");

	printf("======================\n");
	for (int i = 0; i < 2; i++) {
		p.hit(shoe);
	}
	ShowHand(p);
	printf("======================\n");

	if (p.Play(shoe)) {
		d.Play(shoe);

		showResult(p, d);
	}
	else {
		printf("バーストしたので負けです。");
	}
}