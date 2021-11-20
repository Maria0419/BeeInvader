#pragma once
#include "stdafx.h"
#include "EventManager.h"
#include "GraphicManager.h"
#include "Jogador.h"
#include "Curandeira.h"
#include "Fase.h"

class InputManager
{
private:
	Jogador* pJogador1;
	Curandeira* pCurandeira;
	GraphicManager* pGraphic;
	Fase* pFase;
	
	sf::Vector2i mousePosWindow;

public:
	InputManager();
	~InputManager();

	void update(float deltaTime);
	void updateAtaqueFadaCaida();
	void updateAtaqueCurandeira();
	void updateMousePos();
	void updateFadaCaida(float deltaTime);
	void updateCurandeira(float deltaTime);
	void setJogador(Jogador* pJogador);
	void setCurandeira(Curandeira* pC);
	void setGraphicManager(GraphicManager* pGM);
	void setFase(Fase* pFase);
	const sf::Vector2i getMousePos() const;
	const bool getPause() const;
};

