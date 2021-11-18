#pragma once
#include "Entidade.h"
class Projetil :
    public Entidade
{
private:
    float tempo;
public:
    Projetil();
    Projetil(float pos_x, float pos_y, float dir_x, float dir_y, float velocidade, float x_jogador, float y_jogador);
    ~Projetil();

    void renderProjetil();
    float getDirecao_x();
    float getDirecao_y();

    void setShowing(bool x);
    const bool getShowing() const;

    void setPodeMatar(bool x);
    const bool getPodeMatar() const;

    void updateProjetil();
};

