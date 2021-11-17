#pragma once
#include "Personagem.h"

class Jogador :
    public Personagem
{
private:

    sf::RectangleShape barraVida;
    sf::RectangleShape barraVidaFundo;

    //private functions
    void initShape();
    void initBarraVida();
    bool olhaEsquerda;

public:
    Jogador();
    ~Jogador();

    void setOlhaEsquerda(bool x);
    const bool olhandoEsquerda() const;

    void trocaLado();
    
    void naColisao(sf::Vector2f direcao);

    void updateBarraVida();
    void updateAnimacao();
    void update();

    void renderBarraVida();    
   
};

