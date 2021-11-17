#pragma once
#include "Entidade.h"
class Personagem :
    public Entidade
{
protected:
    int num_vidas;
    int dano;
    int points;

    //Pulo
    bool podePular;
    float alturaPulo;

    float cooldownAtaque;
    float cooldownAtaqueMax;
    bool podeAtacar;
    
    
public:
    Personagem();
    Personagem(int n_vida, int dmg, int pontos);
    ~Personagem();

    void setPodePular(bool pode);
    const bool getPodePular() const;
    float getAlturaPulo() const;

    const bool getPodeAtacar();

    void updateAtaqueCooldown();
};

