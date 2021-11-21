#pragma once
#include "Background.h"
#include "Button.h"

class Menu
{
protected:
    Background background;
    sf::Text texto;
    std::map<std::string, Button*> buttons;

    virtual void initButtons() = 0;

public:
    Menu(const char* file, float escala);
    ~Menu();


};
