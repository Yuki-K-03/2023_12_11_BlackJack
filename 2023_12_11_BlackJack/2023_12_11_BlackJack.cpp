#include <iostream>
#include <ctime>
#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"
using namespace std;

const int NUMBER_MAX = 13;
const char* CARD_NUMBER[] = { "Joker", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
const char* CARD_SUIT[] = { "h", "d", "s", "c" };


void ShowHand(Person& person) {
	printf("========================\n");
	printf("Dealer\n");
	person.showName();
	printf("\n\nHand\n");
	person.showHand();
	printf("\n\nScore\n");
	person.showScore();
	printf("\n========================\n");
}

void ShowHand(Person& p1, Person& p2, Person& p3, Person& p4) {
	const Person* players[] = { &p1, &p2, &p3, &p4 };
	int size = (sizeof players / sizeof players[0] - 1);

	printf("\n");
	for (int i = 0, end = size; i <= end; i++) {
		printf("========================  ");
	}
	printf("\nPlayers\n");
	// 名前
	for (int i = 0, end = size; i <= end; i++) {
		players[i]->showName();
	}
	printf("\n\n");
	// 手札
	for (int i = 0, end = size; i <= end; i++) {
		printf("%-26s", "Hand");
	}
	printf("\n");
	for (int i = 0, end = size; i <= end; i++) {
		players[i]->showHand();
	}
	printf("\n\n");
	// スコア
	for (int i = 0, end = size; i <= end; i++) {
		printf("%-26s", "Score");
	}
	printf("\n");
	for (int i = 0, end = size; i <= end; i++) {
		players[i]->showScore();
	}
	printf("\n");
	
	for (int i = 0, end = size; i <= end; i++) {
		printf("========================  ");
	}
	printf("\n");
}

static void showResult(Player& p1, Player& p2, Player& p3, Player& p4, Dealer& dealer)
{
	const Player* players[] = { &p1, &p2, &p3, &p4 };
	int size = (sizeof players / sizeof players[0] - 1);

	printf("\n========================\n");
	printf("         RESULT           ");
	printf("\n========================\n");
	ShowHand(dealer);
	ShowHand(p1, p2, p3, p4);


	for (int i = 0, end = size; i <= end; i++) {
		if (players[i]->calcScore() > dealer.calcScore()) {
			printf("%s Win\n", players[i]->getName());
	}
		else if (players[i]->calcScore() < dealer.calcScore()) {
			printf("%s Lose\n", players[i]->getName());
	}
	else {
			printf("%s Push\n", players[i]->getName());
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
 	Player p1("Player1");
	Player p2("Player2");
	Player p3("Player3");
	Player p4("Player4");
	Player* players[4] = { &p1, &p2, &p3, &p4 };
	int size = (sizeof players / sizeof players[0] - 1);

	Dealer d("Dealer");
	Shoe shoe;
	shoe._shuffle();

	d.hit(shoe);
	ShowHand(d);
	d.hit(shoe);
	
	for (int i = 0, end = size; i <= end; i++) {
		for (int j = 0; j < 2; j++) {
			players[i]->hit(shoe);
		}
	}
	ShowHand(p1, p2, p3, p4);

	bool dealerFlag = false;
	for (int i = 0, end = size; i <= end; i++) {
		if (players[i]->Play(shoe)) {
			dealerFlag = true;
		}
	}

	if (dealerFlag) {
		d.Play(shoe);

		showResult(p1, p2, p3, p4, d);
	}
	else {
		printf("全員バーストしたので負けです。");
	}
}