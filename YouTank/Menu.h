#pragma once
#include "Background.h"
#include "Button.h"

class Menu
{
protected:
    static GraphicManager* pGraphic;
    Background background;
    sf::Text texto;
    sf::Font* fonte;
    std::map<std::string, Button*> buttons;

   // virtual void initButtons() = 0;

public:
    Menu(const char* file);
    ~Menu();
    static void setGraphicManager(GraphicManager* pGM);
    void renderButtons();
    void renderText();
};

