#pragma once
#include "Fase.h"
class FasePrimeira :
    public Fase
{
private:

    unsigned int contaPoteMel;

public:
    FasePrimeira();
    ~FasePrimeira();

    //Funçoes
    void spawnCogumelo();
    void spawnPlataforma();
    void spawnObstaculos();
    void spawnAbelhas();
    void spawnPoteMel();
    void updateFasePrimeira();
    void update();

    void renderFasePrimeira();

    const bool getTerminou() const;
};

