#pragma once
#include "GraphicManager.h"
#include "InputManager.h"

enum qual_state {STATE = 0, MENU_STATE, GAME_STATE };

class State
{
private:
	
protected:
	static GraphicManager* pGraphic;
	InputManager* pInput;
	std::stack<State*>* states;

	short stateID;

	bool terminar;

public:
	State(std::stack<State*>* state);
	virtual ~State();

	static void setGraphicManager(GraphicManager* pGM);

	const bool& getTerminar() const;
	virtual const short getState() = 0;

	virtual void verificarFim();

	virtual void endState() = 0;

	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render() = 0;
};

