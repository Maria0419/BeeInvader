#pragma once
#include "ListaEntidades.h"
#include "CollisionManager.h"
#include "Jogador.h"
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

class Fase :
    public Ente
{
protected:
    ListaEntidades listaEntidades;
    Entidade* pEn;
    CollisionManager collisionManager;
    Curandeira* pCurandeira;

    //Jogador
    static Jogador* pJogador;

public:
    Fase();
    ~Fase();
    void limpeza();

    virtual void update();

    void setJogador(Jogador* pJ);
};

