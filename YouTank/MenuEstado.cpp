#include "stdafx.h"
#include "MenuEstado.h"
using namespace ElementosVisuais;

void MenuEstado::initText()
{

	//Inicializa o texto do botão
	fonte = pGrafico->getFont();

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

void MenuEstado::initBotoes()
{
	botoes["NOVO_JOGO"] = new Botao(175, "Novo Jogo");
	botoes["CONTINUAR_JOGO"] = new Botao(250, "Continuar Jogo");
	botoes["FASE_1"] = new Botao(325, "Primeira Fase");
	botoes["FASE_2"] = new Botao(400, "Segunda Fase");
	botoes["MULTIPLAYER"] = new Botao(475, "Multiplayer");
	botoes["RANKING"] = new Botao(550, "Ranking");
	botoes["SAIR"] = new Botao(625, "Sair");
}

MenuEstado::MenuEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC):
	Estado(estado, pGC, MENU_ESTADO),
	Menu("Imagens/menu.png")
{
	initBotoes();
	initText();
}

MenuEstado::~MenuEstado()
{
	deletarBotoes();
	texto.clear();
}

const short MenuEstado::getEstado()
{
	return estadoID;
}

void MenuEstado::updateBotoes()
{
	for (auto& it : botoes)
	{
		it.second->update((const float) (pComando->getMousePos().x), (const float) (pComando->getMousePos().y));
	}

	if (botoes["NOVO_JOGO"]->estaPressionado())
	{
		estados->push(new JogoEstado(estados, pComando, 12));
		estados->push(new NomeEstado(estados, pComando));
		
	}
	if (botoes["CONTINUAR_JOGO"]->estaPressionado())
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
	else if (botoes["FASE_1"]->estaPressionado())
	{
		estados->push(new JogoEstado(estados, pComando, 1));
		estados->push(new NomeEstado(estados, pComando));
	}
	else if (botoes["FASE_2"]->estaPressionado())
	{
		estados->push(new JogoEstado(estados, pComando, 2));
		estados->push(new NomeEstado(estados, pComando));
	}
	else if (botoes["MULTIPLAYER"]->estaPressionado())
	{
		estados->push(new JogoEstado(estados, pComando, 12, true));
		estados->push(new NomeEstado(estados, pComando));
	}
	else if (botoes["RANKING"]->estaPressionado())
	{
		estados->push(new RankingEstado(estados, pComando));
	}
	else if (botoes["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void MenuEstado::updateComando()
{
	pComando->updateMousePos();
}

void MenuEstado::update()
{
	updateComando();
	updateBotoes();
	
}

void MenuEstado::render()
{
	plano_fundo.render();
	renderText();
	renderBotoes();
}

