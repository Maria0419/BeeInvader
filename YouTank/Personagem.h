#pragma once
#include "Entidade.h"
class Personagem :
    public Entidade
{
protected:
    //Pulo
    bool podePular;
    float alturaPulo;

    float cooldownAtaque;
    float cooldownAtaqueMax;
    bool podeAtacar;
    
    
public:
    Personagem(int hp, int dmg, int i, int pnts);
    ~Personagem();

    const int getVida() const;
    const int getVidaMAX() const;

    void setPodePular(bool pode);
    const bool getPodePular() const;
    float getAlturaPulo() const;

    const bool getPodeAtacar();

    void updateAtaqueCooldown();
};

