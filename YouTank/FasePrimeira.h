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
    void criarPlataforma();
    void criarObstaculos();
    void criarPoteMel();
    void updateFasePrimeira();
    void update();

    void renderFasePrimeira();
    void salvar();

    void recuperar();
    

    const bool getTerminou() const;
};

