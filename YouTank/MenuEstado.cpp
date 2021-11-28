#include "stdafx.h"
#include "MenuEstado.h"
using namespace ElementosVisuais;

void MenuEstado::initText()
{

	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	sf::Text titulo;
	texto.push_back(titulo);
	texto[0].setFont(*fonte);
	texto[0].setString("BEEINVADER");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(370.f, 0.f);

}

void MenuEstado::initButtons()
{
	buttons["NOVO_JOGO"] = new Button(175, "Novo Jogo");
	buttons["CONTINUAR_JOGO"] = new Button(250, "Continuar Jogo");
	buttons["FASE_1"] = new Button(325, "Primeira Fase");
	buttons["FASE_2"] = new Button(400, "Segunda Fase");
	buttons["MULTIPLAYER"] = new Button(475, "Multiplayer");
	buttons["RANKING"] = new Button(550, "Ranking");
	buttons["SAIR"] = new Button(625, "Sair");
}

MenuEstado::MenuEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM):
	Estado(estado, pIM, MENU_STATE),
	Menu("Imagens/menu.png")
{
	initButtons();
	initText();
}

MenuEstado::~MenuEstado()
{
	deletarButtons();
	texto.clear();
}

const short MenuEstado::getEstado()
{
	return estadoID;
}

void MenuEstado::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float) (pComando->getMousePos().x), (const float) (pComando->getMousePos().y));
	}

	if (buttons["NOVO_JOGO"]->estaPressionado())
	{
		estados->push(new JogoEstado(estados, pComando, 12));
		estados->push(new NomeEstado(estados, pComando));
		
	}
	if (buttons["CONTINUAR_JOGO"]->estaPressionado())
	{
		std::ifstream recuperar("./Carregamentos/ConfiguracoesFase.txt", std::ios::in);
		if (!recuperar)
		{
			std::cout << "arquivo não pode ser aberto" << std::endl;
			fflush(stdin);
			return;
		}
		std::string nome;
		int fase;
		bool multiPlayer;
		recuperar >> nome >> fase >> multiPlayer;
		recuperar.close();

		estados->push(new JogoEstado(estados, pComando, fase, multiPlayer, true));
		estados->top()->setNome(nome);
		estados->top()->recuperar();
	}
	else if (buttons["FASE_1"]->estaPressionado())
	{
		estados->push(new JogoEstado(estados, pComando, 1));
		estados->push(new NomeEstado(estados, pComando));
	}
	else if (buttons["FASE_2"]->estaPressionado())
	{
		estados->push(new JogoEstado(estados, pComando, 2));
		estados->push(new NomeEstado(estados, pComando));
	}
	else if (buttons["MULTIPLAYER"]->estaPressionado())
	{
		estados->push(new JogoEstado(estados, pComando, 12, true));
		estados->push(new NomeEstado(estados, pComando));
	}
	else if (buttons["RANKING"]->estaPressionado())
	{
		estados->push(new RankingEstado(estados, pComando));
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void MenuEstado::updateInput()
{
	pComando->updateMousePos();
}

void MenuEstado::update()
{
	updateInput();
	updateButtons();
	
}

void MenuEstado::render()
{
	background.render();
	renderText();
	renderButtons();
}

