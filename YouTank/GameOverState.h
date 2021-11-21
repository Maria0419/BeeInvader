#pragma once
#include "State.h"
#include "Menu.h"

class GameOverState :
    public State, public Menu
{
private:


public:
	GameOverState();
	~GameOverState()

	const short getState();

	void updateInput();
	void update();
	void render();
};

