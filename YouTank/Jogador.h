#pragma once
#include "Personagem.h"
#include "Orbe.h"
#include "BarraVida.h"

class Jogador :
    public Personagem
{
private:

    BarraVida barraVida;
    Orbe* pOrbe;

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
    void ataca(float dir_x, float dir_y);

    void updateAnimacao();
    
    void update();

    void renderBarraVida();    
   
};

