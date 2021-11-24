#pragma once
#include "Jogador.h"
#include "Orbe.h"
#include "BarraVida.h"

class FadaCaida :
    public Jogador
{
private:
    Orbe* pOrbe;
    bool colisaoBot;

    //private functions
    void initShape();

public:
    FadaCaida();
    ~FadaCaida();

    void ataca(float dir_x, float dir_y);
    void update();
   
};

