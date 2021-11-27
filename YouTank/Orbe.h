#pragma once
#include "Projetil.h"
class Orbe :
    public Projetil
{
private:
public:
    Orbe(float dir_x, float dir_y, float jog_x, float jog_y);
    Orbe(float dir_x, float dir_y, float pos_x, float pos_y, float vel_x, float vel_y);
    ~Orbe();

    void renderOrbe();
    void updateOrbe();

    void salvar();
};

