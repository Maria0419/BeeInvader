#pragma once
#include "Projetil.h"
class Orbe :
    public Projetil
{
private:
public:
    Orbe(float dir_x, float dir_y, float jog_x, float jog_y);
    Orbe();
    ~Orbe();

    void renderOrbe();
    void updateOrbe();

    void salvar();
};

