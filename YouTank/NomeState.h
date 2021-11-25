#pragma once
#include "State.h"
#include "Menu.h"

class NomeState :
    public State, public Menu
{

	void initText();
	void initButtons();

public:
	NomeState(std::stack<State*>* state, InputManager* pIM);
	~NomeState();

	const short getState();

	void updateButtons();
	void updateInput();
	void update();

	void render();
};

