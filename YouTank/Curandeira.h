#pragma once
#include "Jogador.h"
#include "OrbeCura.h"

namespace Jogadores
{
class Curandeira :
    public Jogador
{
private:

    OrbeCura* pOrbeCura;
   
    int cura;
public:
    Curandeira();
    ~Curandeira();

    void curar(float dir_x, float dir_y, float pos_x, float pos_y);
    void update();
    const int getCura() const;
};

}