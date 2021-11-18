#pragma once
#include "Entidade.h"
class Projetil :
    public Entidade
{
private:
    sf::Vector2f direcao;
public:
    Projetil();
    Projetil(float pos_x, float pos_y, float dir_x, float dir_y, float velocidade);
    ~Projetil();

    void renderProjetil();
    float getDirecao_x();
    float getDirecao_y();

    void setShowing(bool x);
    const bool getShowing() const;

    void setPodeMatar(bool x);
    const bool getPodeMatar() const;
};

