#pragma once
#include "stdafx.h"
#include "EventManager.h"
#include "GraphicManager.h"
#include "FadaCaida.h"
#include "Curandeira.h"
#include "Fase.h"

class InputManager
{
private:
	Jogadores::FadaCaida* pFadaCaida;
	Jogadores::Curandeira* pCurandeira;
	GraphicManager* pGraphic;
	Fases::Fase* pFase;

	sf::Vector2i mousePosWindow;

public:
	InputManager();
	~InputManager();

	//updates
	void update(float deltaTime);
	void updateAtaqueFadaCaida();
	void updateAtaqueCurandeira();
	void updateMousePos();
	void updateFadaCaida(float deltaTime);
	void updateCurandeira(float deltaTime);

	//sets
	void setFadaCaida(Jogadores::FadaCaida* pFada);
	void setCurandeira(Jogadores::Curandeira* pC);
	void setGraphicManager(GraphicManager* pGM);
	void setFase(Fases::Fase* pFase);

	//gets
	const sf::Vector2i getMousePos() const;
	const bool getPause() const;
};

