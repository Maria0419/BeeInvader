#pragma once
#include "Projetil.h"
class Ferrao :
    public Projetil
{
private:
    float jogX;
    float jogY;

public:
    Ferrao(float pos_x, float pos_y, float x_jogador, float y_jogador);
    ~Ferrao();

    void updateFerrao();

    void salvar();
};

