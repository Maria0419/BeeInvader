#pragma once
#include "Inimigo.h"
#include "BarraVida.h"

class Dragao:
	public Inimigo
{
private:
	BarraVida barraVida;

public:
	Dragao();
	~Dragao();
	const bool EmFuria() const;
	void tomarDano(int dmg);
	void curaVida(int x);
	const bool getVida() const;
	void renderDragao();
};

