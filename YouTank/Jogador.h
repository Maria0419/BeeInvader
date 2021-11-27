#pragma once
#include "Personagem.h"
#include "BarraVida.h"
using namespace ElementosVisuais;

namespace Jogadores {
class Jogador :
    public Personagem
{
protected:
    BarraVida barraVida;
    bool colisaoBot;
    std::string arquivo;

public:
    Jogador(int vida, int dano, int id, float barraVida_y, int player, const char* arqv);
    ~Jogador();
    void setOlhaEsquerda(bool x);
    const bool olhandoEsquerda() const;

    void setDirecao_x(float dir_x);
    void setDirecao_y(float dir_y);

    void naColisao();

    const bool getColisaoBot() const;
    const bool getExisteNaFase() const;

    void renderBarraVida();

    void update();
    void updateAnimacao();
    void updateTaVivo();

    void salvar();
    void recuperar();
};
}
