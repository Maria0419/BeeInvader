#include "stdafx.h"
#include "GameWinState.h"
#include "GameState.h"
using namespace ElementosVisuais;

void GameWinState::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	sf::Text gameWin;
	texto.push_back(gameWin);
	texto[0].setFont(*fonte);
	texto[0].setString("VITORIA");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(450.f, 50.f);
}

void GameWinState::initButtons()
{
	if(prox_fase == true)
		buttons["PROX_FASE"] = new Button(225, "Proxima fase");

	buttons["SALVAR_PONTOS"] = new Button(300, "Salvar pontos");
	buttons["VOLTAR_MENU"] = new Button(375, "Voltar ao Menu");
	buttons["SAIR"] = new Button(450, "Sair");
}

GameWinState::GameWinState(std::stack<State*>* state, InputManager* pIM, std::string nome, int pontos, bool prox_f, bool mp) :
	State(state, pIM, GWIN_STATE),
	Menu("Imagens/treeForest.jpg")
{
	nomeJ = nome;
	pontuacao = pontos;
	prox_fase = prox_f;
	multiplayer = mp;
	gameOver = true;
	initButtons();
	initText();
}

GameWinState::~GameWinState()
{
	deletarButtons();
	ranking.clear();
}

const short GameWinState::getState()
{
	return stateID;
}

void GameWinState::recuperarPontuacao()
{
	std::ifstream recuperaPontos("ranking.txt", std::ios::in);
	if (!recuperaPontos)
	{
		std::cout << "erro ao abrir arquivo de ranking" << std::endl;
		fflush(stdin);
		return;
	}

	while (!recuperaPontos.eof())
	{

		std::string nome;
		int pnts;
		recuperaPontos >> nome >> pnts;
		if (nome != "")
		{
			ranking.insert(std::multimap<int, std::string,  std::greater<int>>::value_type(pnts, nome));
		}
	}
	recuperaPontos.close();
}

void GameWinState::salvarPontuacao()
{
	ranking.insert(std::multimap<int, std::string, std::greater<int>>::value_type(pontuacao, nomeJ));

	std::ofstream pontosFile("ranking.txt", std::ios::out);
	if (!pontosFile)
	{
		std::cout << "arquivo não pode ser aberto" << std::endl;
		fflush(stdin);
		return;
	}	
	pontosFile.clear();
	std::multimap<int, std::string, std::greater<int>>::iterator it;
	for (it = ranking.begin(); it != ranking.end(); ++it)
	{
		pontosFile << it->second << ' ' << it->first << std::endl;
	}

	buttons["SALVAR_PONTOS"]->setText("SALVO");

	pontosFile.close();
}

void GameWinState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pInput->getMousePos().x), (const float)(pInput->getMousePos().y));
	}
	if (prox_fase)
	{
		if (buttons["PROX_FASE"]->estaPressionado())
		{
			if (multiplayer == true)
			{
				states->push(new GameState(states, pInput, 2, true));
				states->top()->setNome(nomeJ);
				states->top()->setPontos(pontuacao);
			}

			else
			{
				states->push(new GameState(states, pInput, 2, false));
				states->top()->setNome(nomeJ);
				states->top()->setPontos(pontuacao);
			}
				

		}
	}
	if (buttons["SALVAR_PONTOS"]->estaPressionado())
	{
		recuperarPontuacao();
		salvarPontuacao();
	}
	if (buttons["VOLTAR_MENU"]->estaPressionado())
	{
		goToMenu = true;
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void GameWinState::updateInput()
{
	pInput->updateMousePos();
}

void GameWinState::update()
{
	updateInput();
	updateButtons();
}

void GameWinState::render()
{
	background.render();
	renderText();
	renderButtons();
}