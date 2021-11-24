#pragma once
#include "ListaEntidades.h"
#include "CollisionManager.h"
#include "FadaCaida.h"
#include "Orbe.h"
#include "ListaEntidades.h"
#include "Abelha.h"
#include "Ferrao.h"
#include "Plataforma.h"
#include "Background.h"
#include "Cogumelo.h"
#include "Curandeira.h"
#include "Espinhos.h"
#include "Pedra.h"
#include "FavoMel.h"
#include "PoteMel.h"

class Fase :
    public Ente
{
protected:
    ListaEntidades listaEntidades;
    CollisionManager collisionManager;

    //FadaCaidaes
    FadaCaida* pFadaCaida;
    Curandeira* pCurandeira;

    Background background;

    //Timer dos inimigos
    unsigned int criarTimer;
    unsigned int criarTimerMAX;
    unsigned int abelhasMAX;
    unsigned int contaAbelhas;
    unsigned int cogumelosMAX;
    unsigned int contaCogu;
    unsigned int obstaculosMAX;
    unsigned int contaObstaculos;
    unsigned int contaPedras;

    //privateFunctions
    void initInimigo();


public:
    Fase();
    ~Fase();
    void limpeza();

    void criarCogumelos();
    void criarAbelhas(int i);

    virtual void update();
    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void updateInimigoPlataforma();
    virtual void setFadaCaida(FadaCaida* pJ);
    void setCurandeira(Curandeira* pC);
};

