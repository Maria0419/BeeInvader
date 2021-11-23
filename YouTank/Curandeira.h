#pragma once
#include "Personagem.h"
#include "OrbeCura.h"
class Curandeira :
    public Personagem
{
private:

    OrbeCura* pOrbeCura;
    bool colisaoBot;
    int cura;
public:
    Curandeira();
    ~Curandeira();


    void setDirecao_x(float dir_x);
    void setDirecao_y(float dir_y);

    void setOlhaEsquerda(bool x);
    const bool olhandoEsquerda() const;

    void update();
    void updateAnimacao();

    void naColisao();
    void curar(float dir_x, float dir_y, float pos_x, float pos_y);

    const int getCura() const;
    const bool getColisaoBot() const;
};

