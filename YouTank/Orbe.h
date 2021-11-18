#pragma once
#include "Projetil.h"
class Orbe :
    public Projetil
{
private:
public:
    Orbe();
    Orbe(float dir_x, float dir_y, float velocidade, float x_jogador, float y_jogador);
    ~Orbe();

    void renderOrbe();
    void updateOrbe();
};

