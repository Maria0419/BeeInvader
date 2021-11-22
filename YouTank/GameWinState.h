#pragma once
#include "State.h"
#include "Menu.h"
class GameWinState :
    public State, public Menu
{
private:

	void initText();
	void initButtons();
public:
	GameWinState(std::stack<State*>* state, InputManager* pIM);
	~GameWinState();

	const short getState();

	void updateButtons();
	void updateInput();
	void update();

	void render();
};

