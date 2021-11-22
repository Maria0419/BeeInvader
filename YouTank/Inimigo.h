#pragma once
#include "Personagem.h"
class Inimigo :
    public Personagem
{
private:

public:
    Inimigo(int vida, int dano, int i);
    ~Inimigo();
};

