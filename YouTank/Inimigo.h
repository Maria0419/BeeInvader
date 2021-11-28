#pragma once
#include "Personagem.h"

namespace Inimigos
{

class Inimigo :
    public Personagem
{
private:

public:
    Inimigo(int vida, int dano, int i, int pnts);
    ~Inimigo();
};


}