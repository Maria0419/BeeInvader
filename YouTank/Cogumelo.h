#pragma once
#include "Inimigo.h"

class Cogumelo :
	public Inimigo
{
private:
public:
	Cogumelo();
	Cogumelo(float velX, float posX, float posY);
	~Cogumelo();
	void updateAnimacao();
	void updateCogumelo();

	void salvar();
};

