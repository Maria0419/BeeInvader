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

    int pontos;
    //vida e dano

    int dano;
    int vida;
    int vidaMAX;
   

public:
    Entidade(int hp, int dmg, int i, int pnts);
    Entidade(int i);
    ~Entidade();

    //vida e dano
    virtual void tomarDano(int dmg);
    const int getDano() const;

    void receberCura(int cura);
 
    void setRapidez(float rapidez);
    float getRapidez() const;

    void setVelocidadeX(float x);
    void setVelocidadeY(float y);

    float getVelocidadeX();
    float getVelocidadeY();

    void move(float dx, float dy);
    const bool getShowing() const;

    virtual void setDirecao_x(float dir_x);
    virtual void setDirecao_y(float dir_y);
    
    virtual float getDirecao_x();
    virtual float getDirecao_y();

    virtual void setPodeMatar(bool x);
    virtual const bool getPodeMatar() const;

    const int getPontos() const;

    virtual void persegue(float x_jogador, float y_jogador);
    virtual void updateOrbe();
    virtual void updateOrbeCura();
    virtual void updateFerrao();
    virtual void updateAnimacao();
    virtual void updateCogumelo();

    virtual void movePlataforma();
    virtual void naColisao();

    virtual void operator+=(int i);
};

