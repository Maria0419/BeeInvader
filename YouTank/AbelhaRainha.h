#pragma once
#include "Inimigo.h"
#include "BarraVida.h"
#include "Ferrao.h"
#include "Abelha.h"
#include "FadaCaida.h"

class AbelhaRainha:
	public Inimigo
{
private:
	BarraVida barraVida;
	float originX;
	float x;
	float y;
	unsigned int curaTimer;
	unsigned int curaTimerMAX;
	unsigned int ferraoTimer;
	unsigned int ferraoTimerMAX;
	
	float angulo;
	float anguloMAX;
	Ferrao* pFerrao;
	Abelha* pAbelha;
	FadaCaida* pFadaCaida;

	void initTimers();
	void initShape();

public:
	AbelhaRainha();
	~AbelhaRainha();
	const bool emFuria();
	void curaVida();

	void update();
	void updateAtaque();
	void updateMovimento();
	void updateTaVivo();
	void renderAbelhaRainha();

	void setFadaCaidaAlvo(FadaCaida* pJ);

	const bool getExisteNaFase() const;

};

