#pragma once
#include "stdafx.h"
#include "EventManager.h"
#include "GraphicManager.h"
#include "Jogador.h"
#include "Fase.h"

class InputManager
{
private:
	Jogador* pJogador1;
	GraphicManager* pGraphic;
	Fase* pFase;
	
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:
	InputManager();
	~InputManager();

	void updateAtaque();
	void updateMousePos();
	void update(float deltaTime);

	void setJogador(Jogador* pJogador);
	void setGraphicManager(GraphicManager* pGM);
	void setFase(Fase* pFase);

	const sf::Vector2i getMousePos() const;
	
};

