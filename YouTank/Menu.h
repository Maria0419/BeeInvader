#pragma once
#include "Background.h"
#include "Button.h"
using namespace ElementosVisuais;

class Menu:public Ente
{
protected:
    Background background;
    std::vector<sf::Text> texto;
    sf::Font* fonte;
    std::map<std::string, Button*> buttons;

public:
    Menu(const char* file);
    virtual ~Menu();
    void deletarButtons();
    void renderButtons();
    void renderText();
};

