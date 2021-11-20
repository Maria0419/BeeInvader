#pragma once
#include "Obstaculo.h"
class Pedra :
    public Obstaculo
{
public:
    Pedra(float pos_x, float pos_y);
    ~Pedra();
};

