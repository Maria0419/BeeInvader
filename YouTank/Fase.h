#pragma once
#include "ListaEntidades.h"
#include "CollisionManager.h"
#include "Jogador.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Abelha.h"
#include "Plataforma.h"
#include "Background.h"

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

    virtual void executar();
    void gerenciarColisoes();

    virtual void ataca(float dir_x, float dir_y, float x_jogador, float y_jogador);
    void limpeza();

    virtual void update();

    void setJogador(Jogador* pJ);
    void setWindow();

};

