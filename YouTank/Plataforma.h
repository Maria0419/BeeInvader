#pragma once
#include "Obstaculo.h"
class Plataforma :
    public Obstaculo
{
private:
    //private functions
    void initShape();
public:
    Plataforma(float tam_x, float tam_y, float pos_x, float pos_y, float angulo);
    Plataforma();
    ~Plataforma();

    void setShowing(bool x);
    const bool getShowing() const;
};

