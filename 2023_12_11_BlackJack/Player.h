#pragma once
#include "Person.h"
#include "common.h"

class Shoe;

class Player : public Person{
public :
	Player(const char* name);
	virtual ~Player();
private :
	void PlayBase(Shoe& shoe) override;
};