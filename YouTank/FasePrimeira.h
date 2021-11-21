#pragma once
#include "Fase.h"
class FasePrimeira :
    public Fase
{
private:
    //Background
    Background background;

    unsigned int contaPoteMel;

public:
    FasePrimeira();
    ~FasePrimeira();

    //Funçoes
    void spawnCogumelo();
    void spawnPlataforma();
    void spawnObstaculos();
    void spawnCurandeira();
    void spawnAbelhas();
    void spawnPoteMel();

    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void updateInimigoPlataforma();
    void update();

    void renderFasePrimeira();

    void setFadaCaida(FadaCaida* pFadaCaida);
    Curandeira* getCurandeira() const;
    const bool getTerminou() const;
};

