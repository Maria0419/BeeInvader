#pragma once
#include "Ente.h"
#include "Personagem.h"

namespace ElementosVisuais
{

class BarraVida :
    public Ente
{
private:
    Personagem* pPersonagem;
    float tamanho;

public:
    BarraVida(Personagem* pP, float x, float y, float largura, float altura, int i = 1);
    ~BarraVida();

    void update();
};
}

