#pragma once
#include "Fase.h"
using namespace Fases;
#include "AbelhaRainha.h"

namespace Fases {


class FaseSegunda :
    public Fase
{
private:
    //Boss
    AbelhaRainha* abelha_rainha;

public:
    FaseSegunda();
    ~FaseSegunda();

    //Funçoes
    void criarPlataforma();
    void criarObstaculos();
    void updateBoss();
    void update();

    void renderFaseSegunda();
    void salvar();

    void recuperar();

    void setFadaCaida(FadaCaida* pJ);

    const bool getTerminou() const;
};

}