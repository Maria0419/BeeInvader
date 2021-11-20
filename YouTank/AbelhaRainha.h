#pragma once
#include "Inimigo.h"
#include "BarraVida.h"
#include "Ferrao.h"
#include "Abelha.h"
#include "Jogador.h"

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
	unsigned int spawnTimer;
	unsigned int spawnTimerMAX;
	unsigned int abelhasMAX;
	unsigned int contaAbelhas;
	float angulo;
	float anguloMAX;
	Ferrao* pFerrao;
	Abelha* pAbelha;
	Jogador* pJogador;

public:
	AbelhaRainha();
	~AbelhaRainha();
	const bool emFuria();
	void curaVida();

	void update();
	void updateAtaque();
	void updateMovimento();
	void renderAbelhaRainha();

	void setJogadorAlvo(Jogador* pJ);
	void spawnAbelhas();

	void morreuAbelha();

};

