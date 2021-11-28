#pragma once
#include "Inimigo.h"

namespace Inimigos
{
    class Abelha :
        public Inimigo
    {
    private:
        //private functions
        void initShape();
    public:
        Abelha(int i);
        Abelha(float posX, float posY);
        ~Abelha();

        float getDirecao_x();
        float getDirecao_y();

        void setShowing(bool x);
        const bool getShowing() const;
        void persegue(float x_jogador, float y_jogador);

        void salvar();
    };

}