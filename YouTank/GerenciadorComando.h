#pragma once
#include "stdafx.h"
#include "GerenciadorEvento.h"
#include "GerenciadorGrafico.h"
#include "FadaCaida.h"
#include "Curandeira.h"
#include "Fase.h"

class GerenciadorComando
{
private:
	GerenciadorGrafico* pGrafico;

	Jogadores::FadaCaida* pFadaCaida;
	Jogadores::Curandeira* pCurandeira;
	
	Fases::Fase* pFase;

	sf::Vector2i mousePosWindow;

public:
	GerenciadorComando();
	~GerenciadorComando();

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
	void setGerenciadorGrafico(GerenciadorGrafico* pGG);
	void setFase(Fases::Fase* pFase);

	//gets
	const sf::Vector2i getMousePos() const;
	const bool getPause() const;
};

