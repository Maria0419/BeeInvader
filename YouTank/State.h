#pragma once
#include "GraphicManager.h"
#include "InputManager.h"

enum qual_state {STATE = 0, MENU_STATE, GAME_STATE, PAUSE_STATE, GOVER_STATE };

class State
{
private:
	
protected:
	static GraphicManager* pGraphic;
	InputManager* pInput;
	std::stack<State*>* states;

	short stateID;

	bool sair;
	bool pause;
	bool gameOver;
	bool goToMenu;

public:
	State(std::stack<State*>* state, InputManager* pIM);
	virtual ~State();

	static void setGraphicManager(GraphicManager* pGM);

	virtual void setPause(bool p);

	const bool getSair() const;
	virtual const short getState() = 0;
	virtual const bool getPause() const;
	virtual const bool getGameOver() const;
	virtual const bool getGoToMenu() const;

	virtual void verificarPause();
	virtual void verificarGoToMenu();

	virtual void endState() ;

	virtual void updateInput() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};

