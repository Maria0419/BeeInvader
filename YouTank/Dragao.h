#pragma once
#include "Inimigo.h"
#include "BarraVida.h"

class Dragao:
	public Inimigo
{
private:
	BarraVida barraVida;
	float curaTimer;
	float curaTimerMAX;

public:
	Dragao();
	~Dragao();
	const bool EmFuria() const;
	void curaVida(int x);

	void update();
	void renderDragao();
};

