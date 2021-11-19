#pragma once

#include "Projetil.h"
class OrbeCura :
    public Projetil
{
private:
public:
    OrbeCura();
    OrbeCura(float x_jogador, float y_jogador);
    ~OrbeCura();

    void updateOrbeCura();
};

