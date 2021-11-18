#pragma once
#include "Entidade.h"
class Personagem :
    public Entidade
{
protected:
    
    int pontos;

    //Pulo
    bool podePular;
    float alturaPulo;

    float cooldownAtaque;
    float cooldownAtaqueMax;
    bool podeAtacar;
    
    
public:
    Personagem();
    Personagem(int n_vida, int dmg);
    ~Personagem();

    const int getVida() const;
    const int getVidaMAX() const;

    void setPodePular(bool pode);
    const bool getPodePular() const;
    float getAlturaPulo() const;

    const bool getPodeAtacar();

    void updateAtaqueCooldown();
};

