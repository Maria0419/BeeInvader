#pragma once
#include "PlanoFundo.h"
#include "Botao.h"

class Menu:public Ente
{
protected:
    ElementosVisuais::PlanoFundo plano_fundo;
    std::vector<sf::Text> texto;
    sf::Font* fonte;
    std::map<std::string, ElementosVisuais::Botao*> botoes;

public:
    Menu(const char* file);
    virtual ~Menu();
    void deletarBotoes();
    void renderBotoes();
    void renderText();
};

