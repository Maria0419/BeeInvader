#pragma once
#include "Fase.h"

namespace Fases {

    class FasePrimeira :
        public Fase
    {
    private:
        unsigned int contaPoteMel;

    public:
        FasePrimeira();
        ~FasePrimeira();

        //Fun�oes
        void criarPlataforma();
        void criarObstaculos();
        void criarPoteMel();
        void updateFasePrimeira();
        void update();

        void renderFasePrimeira();
        void salvar();

        void recuperar();
        void recuperarPoteMel();

        const bool getTerminou() const;
    };

}