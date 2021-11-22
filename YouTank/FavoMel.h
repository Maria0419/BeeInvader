#pragma once
#include "Obstaculo.h"
class FavoMel :
    public Obstaculo
{
private:
public:
    FavoMel(float tam_x, float tam_y, float pos_x, float pos_y);
    ~FavoMel();

    void movePlataforma();
};

