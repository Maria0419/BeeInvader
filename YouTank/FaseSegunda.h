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
    void criarPlataforma();
    void criarObstaculos();
    void updateBoss();
    void update();

    void renderFaseSegunda();

    const bool getTerminou() const;
};

