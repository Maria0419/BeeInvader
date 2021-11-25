#include "stdafx.h"
#include "RankingState.h"
#include "stdafx.h"

void RankingState::initText()
{

	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	sf::Text pontos;
	texto.push_back(pontos);
	texto[0].setFont(*fonte);
	texto[0].setString("RANKING\n");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(460.f, 30.f);

	std::ifstream recuperaPontos("ranking.txt", std::ios::in);
	if (!recuperaPontos)
	{
		std::cout << "erro ao abrir arquivo de ranking" << std::endl;
		fflush(stdin);
		return;
	}
	int i = 1;
	while (!recuperaPontos.eof())
	{
		
		std::string pontuacao;
		recuperaPontos >> pontuacao;
		if (pontuacao != "\n")
		{
			sf::Text pts;
			texto.push_back(pts);
			texto[i].setFont(*fonte);
			texto[i].setString(pontuacao);
			texto[i].setFillColor(sf::Color::White);
			texto[i].setOutlineColor(sf::Color::Black);
			texto[i].setOutlineThickness(3.f);
			texto[i].setCharacterSize(98);
			texto[i].setPosition(600.f, 60.f * i);
		}
		i++;
	}
	recuperaPontos.close();
}

void RankingState::initButtons()
{
	buttons["VOLTAR_MENU"] = new Button(600, "Voltar ao Menu");
}

RankingState::RankingState(std::stack<State*>* state, InputManager* pIM) :
	State(state, pIM, RANKING_STATE),
	Menu("Imagens/menu.png")
{
	initButtons();
	initText();
}

RankingState::~RankingState()
{
	deletarButtons();
}

const short RankingState::getState()
{
	return stateID;
}

void RankingState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pInput->getMousePos().x), (const float)(pInput->getMousePos().y));
	}
	if (buttons["VOLTAR_MENU"]->estaPressionado())
	{
		goToMenu = true;
	}
}

void RankingState::updateInput()
{
	pInput->updateMousePos();
}

void RankingState::update()
{
	updateInput();
	updateButtons();

}

void RankingState::render()
{
	background.render();
	renderText();
	renderButtons();
}

