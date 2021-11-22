#pragma once
#include "State.h"
#include "Menu.h"

class GameOverState :
    public State, public Menu
{
private:
	void initText();
	void initButtons();

public:
	GameOverState(std::stack<State*>* state, InputManager* pIM);
	~GameOverState();

	const short getState();

	void updateButtons();
	void updateInput();
	void update();

	void render();
};

