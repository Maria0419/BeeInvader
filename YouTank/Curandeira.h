#pragma once
#include "Personagem.h"
#include "OrbeCura.h"
class Curandeira :
    public Personagem
{
private:
    OrbeCura* pOrbeCura;
public:
    Curandeira();
    ~Curandeira();

    void cura(float dir_x, float dir_y);
};

