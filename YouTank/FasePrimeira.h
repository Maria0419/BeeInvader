#pragma once
#include "Fase.h"
using namespace Fases;

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


        const bool getTerminou() const;
    };

}