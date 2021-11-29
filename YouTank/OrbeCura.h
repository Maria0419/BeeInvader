#pragma once

#include "Projetil.h"
class OrbeCura :
    public Projetil
{
private:
    float dirX;
    float dirY;
public:
    OrbeCura(float x_dir, float y_dir, float x_pos, float y_pos);
    ~OrbeCura();

    void salvar();

    void update();
};

