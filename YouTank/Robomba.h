#pragma once
#include "Inimigo.h"
#include "BarraVida.h"

class Robomba:
	public Inimigo
{
private:
	BarraVida barraVida;

public:
	Robomba();
	~Robomba();
	const bool EmFuria() const;
	void tomarDano(int dmg);
	void curaVida(int x);
	const bool getVida() const;
	void renderRobomba();
};

