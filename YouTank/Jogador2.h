#pragma once
#include "Personagem.h"
class Jogador2:
	public Personagem
{
private:
public:
	Jogador2();
	~Jogador2();
	void setOlhaEsquerda(bool x);
	const bool olhandoEsquerda() const;

	void update();
	void updateAnimacao();
};

