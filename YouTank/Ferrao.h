#pragma once
#include "Projetil.h"
class Ferrao :
    public Projetil
{
private:

public:
    Ferrao(float pos_x, float pos_y, float x_jogador, float y_jogador);
    ~Ferrao();

    void update();

    void salvar();
};

