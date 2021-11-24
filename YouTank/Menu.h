#pragma once
#include "Background.h"
#include "Button.h"

class Menu:public Ente
{
protected:
    Background background;
    sf::Text texto;
    sf::Font* fonte;
    std::map<std::string, Button*> buttons;

   // virtual void initButtons() = 0;

public:
    Menu(const char* file);
    virtual ~Menu();
    void deletarButtons();
    void renderButtons();
    void renderText();
};

