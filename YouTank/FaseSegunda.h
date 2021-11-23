#pragma once
#include "Fase.h"
#include "AbelhaRainha.h"

class FaseSegunda :
    public Fase
{
private:
    //Boss
    AbelhaRainha abelha_rainha;

public:
    FaseSegunda();
    ~FaseSegunda();

    //Funçoes
    void spawnCogumelo();
    void spawnAbelhas();
    void spawnPlataforma();
    void spawnObstaculos();
    void spawnCurandeira();
    void updateBoss();
    void update();

    void renderFaseSegunda();

    void setFadaCaida(FadaCaida* pFadaCaida);
    Curandeira* getCurandeira() const;
    const bool getTerminou() const;
};

