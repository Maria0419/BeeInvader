#pragma once
#include "Personagem.h"
#include "BarraVida.h"

class Jogador :
    public Personagem
{
private:

    BarraVida barraVida;

    //private functions
    void initShape();
    void initBarraVida();
    bool olhaEsquerda;

public:
    Jogador();
    ~Jogador();

    void setOlhaEsquerda(bool x);
    const bool olhandoEsquerda() const;
    
    void naColisao(sf::Vector2f direcao);

    void updateBarraVida();
    void updateAnimacao();
    void update();

    void renderBarraVida();    
   
};

