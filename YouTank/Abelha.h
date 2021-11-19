#pragma once
#include "Inimigo.h"
class Abelha :
    public Inimigo
{
private:
    //private functions
    void initShape();
public:
    Abelha();
    ~Abelha();

    float getDirecao_x();
    float getDirecao_y();

    void setShowing(bool x);
    const bool getShowing() const;
    void persegue(float x_jogador, float y_jogador);
};

