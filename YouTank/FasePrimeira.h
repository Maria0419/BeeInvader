#pragma once
#include "Fase.h"
class FasePrimeira :
    public Fase
{
private:
    sf::Clock timer;
    unsigned int contaPoteMel;

public:
    FasePrimeira();
    ~FasePrimeira();

    //Funçoes
    void criarPlataforma();
    void criarObstaculos();
    void criarPoteMel();
    void updateFasePrimeira();
    void update();

    void renderFasePrimeira();

    const bool getTerminou() const;
};

