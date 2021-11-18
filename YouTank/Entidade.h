#pragma once
#include "Ente.h"

class Entidade :
    public Ente
{
protected:
    //Velocidade de movimento
    sf::Vector2f velocidade;
    sf::Vector2f direcao;
    sf::Vector2f destino;
    sf::Vector2f posicaoInicial;
    float rapidez;
    bool podeMatar;
   

public:
    Entidade();
    ~Entidade();
    virtual void executar();

    void setRapidez(float rapidez);
    float getRapidez() const;

    void setVelocidadeX(float x);
    void setVelocidadeY(float y);

    float getVelocidadeX();
    float getVelocidadeY();

    void move(float dx, float dy);
    
    virtual float getDirecao_x();
    virtual float getDirecao_y();

    virtual void setPodeMatar(bool x);
    virtual const bool getPodeMatar() const;

    virtual void persegue();
    virtual void updateProjetil();
};

