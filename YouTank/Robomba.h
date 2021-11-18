#pragma once
#include "Inimigo.h"

class Robomba:
	public Inimigo
{
private:
public:
	Robomba();
	~Robomba();
	const bool EmFuria() const;
	void tomarDano(int dmg);
	void curaVida(float x);
	const bool getVida() const;
};

