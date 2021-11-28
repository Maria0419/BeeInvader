#include "stdafx.h"
#include "RankingEstado.h"
using namespace ElementosVisuais;

void RankingEstado::initText()
{

	//Inicializa o texto do botão
	fonte = pGrafico->getFont();

	sf::Text ranking;
	texto.push_back(ranking);
	texto[0].setFont(*fonte);
	texto[0].setString("RANKING\n");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(460.f, 30.f);

	std::ifstream recuperaPontos("./Carregamentos/ranking.txt", std::ios::in);
	if (!recuperaPontos)
	{
		std::cout << "erro ao abrir arquivo de ranking" << std::endl;
		fflush(stdin);
		return;
	}
	int i = 1;
	while (!recuperaPontos.eof() && i<=6)
	{
		std::string nome;
		int pontos;
		recuperaPontos >> nome >> pontos;
		std::stringstream ss;
		ss << i << ". " << nome << ' ' << pontos;

		if (nome != "")
		{
			sf::Text pts;
			texto.push_back(pts);
			texto[i].setFont(*fonte);
			texto[i].setString(ss.str());
			texto[i].setFillColor(sf::Color::White);
			texto[i].setOutlineColor(sf::Color::Black);
			texto[i].setOutlineThickness(3.f);
			texto[i].setCharacterSize(68);
			texto[i].setPosition(460.f, 100 + 60.f * i);

			i++;
		}
		
	}
	recuperaPontos.close();
}

void RankingEstado::initBotoes()
{
	botoes["VOLTAR_MENU"] = new Botao(600, "Voltar ao Menu");
}

RankingEstado::RankingEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC) :
	Estado(estado, pGC, RANKING_ESTADO),
	Menu("Imagens/menu.png")
{
	initBotoes();
	initText();
}

RankingEstado::~RankingEstado()
{
	deletarBotoes();
	texto.clear();
}

const short RankingEstado::getEstado()
{
	return estadoID;
}

void RankingEstado::updateBotoes()
{
	for (auto& it : botoes)
	{
		it.second->update((const float)(pComando->getMousePos().x), (const float)(pComando->getMousePos().y));
	}
	if (botoes["VOLTAR_MENU"]->estaPressionado())
	{
		irMenu = true;
	}
}

void RankingEstado::updateComando()
{
	pComando->updateMousePos();
}

void RankingEstado::update()
{
	updateComando();
	updateBotoes();

}

void RankingEstado::render()
{
	plano_fundo.render();
	renderText();
	renderBotoes();
}

