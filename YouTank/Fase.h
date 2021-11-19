#pragma once
#include "ListaEntidades.h"
#include "CollisionManager.h"
#include "Jogador.h"
#include "Orbe.h"
#include "ListaEntidades.h"
#include "Abelha.h"
#include "Plataforma.h"
#include "Background.h"
#include "Cogumelo.h"

class Fase :
    public Ente
{
protected:
    ListaEntidades listaEntidades;
    Entidade* pEn;
    CollisionManager collisionManager;

    //Jogador
    static Jogador* pJogador;

public:
    Fase();
    ~Fase();

    virtual void ataca(float dir_x, float dir_y, float x_jogador, float y_jogador);
    void limpeza();

    virtual void update();

    void setJogador(Jogador* pJ);
};

