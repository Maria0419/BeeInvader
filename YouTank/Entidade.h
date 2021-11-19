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
    float rapidez;
    bool podeMatar;
    bool olhaEsquerda;

    //vida e dano
    int dano;
    int vida;
    int vidaMAX;
   

public:
    Entidade(int hp, int dmg);
    Entidade();
    ~Entidade();
    virtual void executar();

    //vida e dano
    virtual void tomarDano(int dmg);
    const int getDano() const;

    void setRapidez(float rapidez);
    float getRapidez() const;

    void setVelocidadeX(float x);
    void setVelocidadeY(float y);

    float getVelocidadeX();
    float getVelocidadeY();

    void move(float dx, float dy);
    const bool getShowing() const;
    
    virtual float getDirecao_x();
    virtual float getDirecao_y();

    virtual void setPodeMatar(bool x);
    virtual const bool getPodeMatar() const;

    virtual void persegue(float x_jogador, float y_jogador);
    virtual void updateOrbe();
    virtual void updateFerrao();

    virtual void naColisao(sf::Vector2f direcao);
};

