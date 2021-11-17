#pragma once
#include "Ente.h"

enum estado_botao{BT_IDLE = 0, BT_EMCIMA, BT_PRESSIONADO};

class Button :
    public Ente
{
private:
    short unsigned estadoBotao;

    sf::Text texto;
    sf::Font* fonte;

    unsigned int red, green, blue;

public:
    Button(float x, float y, float largura, float altura, std::string text);
    ~Button();

    //Gets
    const bool estaPressionado() const;


    void update(const float posX, const float posY);
    void renderText();
};

