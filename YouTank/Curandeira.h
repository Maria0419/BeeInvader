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

    void setOlhaEsquerda(bool x);
    const bool olhandoEsquerda() const;
    void update();
    void updateAnimacao();
    void cura(float dir_x, float dir_y, float pos_x, float pos_y);
};

