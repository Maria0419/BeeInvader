#include "stdafx.h"
#include "MenuState.h"

void MenuState::initText()
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

void MenuState::initButtons()
{
	buttons["NOVO_JOGO"] = new Button(175, "Novo Jogo");
	buttons["CONTINUAR_JOGO"] = new Button(250, "Continuar Jogo");
	buttons["FASE_1"] = new Button(325, "Primeira Fase");
	buttons["FASE_2"] = new Button(400, "Segunda Fase");
	buttons["MULTIPLAYER"] = new Button(475, "Multiplayer");
	buttons["RANKING"] = new Button(550, "Ranking");
	buttons["SAIR"] = new Button(625, "Sair");
}

MenuState::MenuState(std::stack<State*>* state, InputManager* pIM):
	State(state, pIM, MENU_STATE),
	Menu("Imagens/menu.png")
{
	initButtons();
	initText();
}

MenuState::~MenuState()
{
	deletarButtons();
}

const short MenuState::getState()
{
	return stateID;
}

void MenuState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float) (pInput->getMousePos().x), (const float) (pInput->getMousePos().y));
	}

	if (buttons["NOVO_JOGO"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 12));
		states->push(new NomeState(states, pInput));
		
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

		states->push(new GameState(states, pInput, fase, multiPlayer));
		states->top()->setNome(nome);
		states->top()->recuperar();
	}
	else if (buttons["FASE_1"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 1));
		states->push(new NomeState(states, pInput));
	}
	else if (buttons["FASE_2"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 2));
		states->push(new NomeState(states, pInput));
	}
	else if (buttons["MULTIPLAYER"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 12, true));
		states->push(new NomeState(states, pInput));
	}
	else if (buttons["RANKING"]->estaPressionado())
	{
		states->push(new RankingState(states, pInput));
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void MenuState::updateInput()
{
	pInput->updateMousePos();
}

void MenuState::update()
{
	updateInput();
	updateButtons();
	
}

void MenuState::render()
{
	background.render();
	renderText();
	renderButtons();
}

