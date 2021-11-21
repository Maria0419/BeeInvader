#pragma once
#include "Fase.h"
#include "AbelhaRainha.h"

class FaseSegunda :
    public Fase
{
private:
    //Background
    Background background;

    //Boss
    AbelhaRainha abelha_rainha;

public:
    FaseSegunda();
    ~FaseSegunda();

    //Fun�oes
    void spawnCogumelo();
    void spawnAbelhas();
    void spawnPlataforma();
    void spawnObstaculos();
    void spawnCurandeira();
    
    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void updateInimigoPlataforma();
    void updateBoss();
    void update();

    void renderFaseSegunda();

    void setFadaCaida(FadaCaida* pFadaCaida);
    Curandeira* getCurandeira() const;
    const bool getTerminou() const;
};

