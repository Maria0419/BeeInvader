#pragma once
#include "Ente.h"
namespace ElementosVisuais
{
    enum estado_botao { BT_IDLE = 0, BT_EMCIMA, BT_PRESSIONADO };

    class Botao :
        public Ente
    {
    private:
        short unsigned estadoBotao;
        static bool mouseHeld;

        sf::Text texto;
        sf::Font* fonte;

        //cores
        unsigned int red, green, blue;

        void initText(std::string text);
        void initShape(float x, float y);

    public:
        Botao(float y, std::string text);
        ~Botao();

        //Gets
        const bool estaPressionado() const;


        void update(const float posX, const float posY);
        void setText(std::string novoTexto);
        void renderText();
    };

}