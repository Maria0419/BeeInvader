#pragma once
#include "Inimigo.h"
#include "BarraVida.h"

class AbelhaRainha:
	public Inimigo
{
private:
	BarraVida barraVida;
	float curaTimer;
	float curaTimerMAX;

public:
	AbelhaRainha();
	~AbelhaRainha();
	const bool EmFuria() const;
	void curaVida(int x);

	void update();
	void renderAbelhaRainha();
};

