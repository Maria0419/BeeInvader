#pragma once
#include "Entidade.h"
class Personagem :
    public Entidade
{
protected:
    int vida;
    int vidaMAX;
    int dano;
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

    virtual void tomarDano(int dmg);
    const int getVida() const;
    const int getVidaMAX() const;

    void setPodePular(bool pode);
    const bool getPodePular() const;
    float getAlturaPulo() const;

    const bool getPodeAtacar();

    void updateAtaqueCooldown();
};

