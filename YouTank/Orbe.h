#pragma once
#include "Projetil.h"
class Orbe :
    public Projetil
{
private:
public:
    Orbe();
    Orbe(float dir_x, float dir_y, float vel, float jog_x, float jog_y);
    ~Orbe();

    void renderOrbe();
    void updateOrbe();
};

