#include "stdafx.h"
#include "VitoriaJogoEstado.h"
#include "JogoEstado.h"
using namespace ElementosVisuais;

void VitoriaJogoEstado::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	sf::Text vitoriaJogo;
	texto.push_back(vitoriaJogo);
	texto[0].setFont(*fonte);
	texto[0].setString("VITORIA");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(450.f, 50.f);
}

void VitoriaJogoEstado::initButtons()
{
	if(prox_fase == true)
		buttons["PROX_FASE"] = new Button(225, "Proxima fase");

	buttons["SALVAR_PONTOS"] = new Button(300, "Salvar pontos");
	buttons["VOLTAR_MENU"] = new Button(375, "Voltar ao Menu");
	buttons["SAIR"] = new Button(450, "Sair");
}

VitoriaJogoEstado::VitoriaJogoEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM, std::string nome, int pontos, bool prox_f, bool mp) :
	Estado(estado, pIM, GWIN_STATE),
	Menu("Imagens/treeForest.jpg")
{
	nomeJ = nome;
	pontuacao = pontos;
	prox_fase = prox_f;
	multiplayer = mp;
	fimJogo = true;
	initButtons();
	initText();
}

VitoriaJogoEstado::~VitoriaJogoEstado()
{
	deletarButtons();
	texto.clear();
	ranking.clear();
}

const short VitoriaJogoEstado::getEstado()
{
	return estadoID;
}

void VitoriaJogoEstado::salvarPontuacao()
{
	ranking.insert(std::multimap<int, std::string, std::greater<int>>::value_type(pontuacao, nomeJ));

	std::ofstream pontosFile("./Carregamentos/ranking.txt", std::ios::out);
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

void VitoriaJogoEstado::recuperarPontuacao()
{
	//abre o arquivo ranking.txt
	std::ifstream recuperaPontos("./Carregamentos/ranking.txt", std::ios::in);
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
			ranking.insert(std::multimap<int, std::string, std::greater<int>>::value_type(pnts, nome));
		}
	}
	recuperaPontos.close();
}

void VitoriaJogoEstado::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pComando->getMousePos().x), (const float)(pComando->getMousePos().y));
	}
	if (prox_fase)
	{
		if (buttons["PROX_FASE"]->estaPressionado())
		{
			if (multiplayer == true)
			{
				estados->push(new JogoEstado(estados, pComando, 2, true));
				estados->top()->setNome(nomeJ);
				estados->top()->setPontos(pontuacao);
			}

			else
			{
				estados->push(new JogoEstado(estados, pComando, 2, false));
				estados->top()->setNome(nomeJ);
				estados->top()->setPontos(pontuacao);
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
		irMenu = true;
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void VitoriaJogoEstado::updateInput()
{
	pComando->updateMousePos();
}

void VitoriaJogoEstado::update()
{
	updateInput();
	updateButtons();
}

void VitoriaJogoEstado::render()
{
	background.render();
	renderText();
	renderButtons();
}