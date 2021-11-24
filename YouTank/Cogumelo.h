#pragma once
#include "Inimigo.h"

class Cogumelo :
	public Inimigo
{
private:
public:
	Cogumelo();
	~Cogumelo();
	void updateAnimacao();
	void updateCogumelo();
};

