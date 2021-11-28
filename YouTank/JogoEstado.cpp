#include "stdafx.h"
#include "JogoEstado.h"
using namespace Jogadores;
using namespace Fases;

void JogoEstado::executarFase()
{
	jogador1 = new FadaCaida();
	pComando->setFadaCaida(jogador1);

	switch (fase)
	{
	case 12:
	case 1:
		fasePrimeira = new FasePrimeira();
		fasePrimeira->setFadaCaida(jogador1);

		if(recuperacao == false)
			fasePrimeira->criarPlataforma();

		if (multiplayer == true)
		{
			criarCurandeira();
			fasePrimeira->setCurandeira(jogador2);
		}
		pComando->setCurandeira(jogador2);
		pComando->setFase(static_cast<Fase*>(fasePrimeira));
		
		break;

	case 2:
		faseSegunda = new FaseSegunda();
		faseSegunda->setFadaCaida(jogador1);

		if (recuperacao == false)
			faseSegunda->criarPlataforma();

		if (multiplayer == true)
		{
			criarCurandeira();
			faseSegunda->setCurandeira(jogador2);
		}
		pComando->setCurandeira(jogador2);
		pComando->setFase(static_cast<Fase*>(faseSegunda));

		break;

	default:
		std::cout << "ERROR::JOGOESTADO::Fase não existente" << std::endl;
		break;
	}
}

void JogoEstado::updateDeltaTime()
{
	
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 0.017f)
		deltaTime = 0.017f;
}

//Construtora e Destrutora
JogoEstado::JogoEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC, short f, bool mp, bool rec):
	Estado(estado,pGC, JOGO_ESTADO),
	fasePrimeira(NULL),
	faseSegunda(NULL),
	jogador1(NULL),
	jogador2(NULL),
	recuperacao(rec)
{
	multiplayer = mp;
	fase = f;
	clock.restart();
	deltaTime = clock.restart().asSeconds();
	executarFase();
	
}

JogoEstado::~JogoEstado()
{
	delete jogador1;
	jogador1 = NULL;

	if (jogador2)
	{
		delete jogador2;
		jogador2 = NULL;
	}
		

	switch (fase)
	{
	case 12:
	case 1:
		delete fasePrimeira;
		
		break;

	case 2:
		delete faseSegunda;
		break;

	default:
		std::cout << "ERROR::JOGOESTADO::Fase não existente" << std::endl;
		break;
	}
}

void JogoEstado::setPause(bool p)
{
	pause = p;
}

void JogoEstado::setNome(std::string nome)
{
	nomeJ = nome;
}

void JogoEstado::setPontos(int pontos)
{
	jogador1->setPontos(pontos);
}

const short JogoEstado::getEstado()
{
	return estadoID;
}

const bool JogoEstado::getPause() const
{
	return pause;
}

void JogoEstado::criarCurandeira()
{
	jogador2 = new Curandeira();
}

void JogoEstado::verificarFimJogo()
{
	if (jogador1->getExisteNaFase() == false)
		fimJogo = true;

	if (multiplayer == true)
	{
		if (jogador2->getExisteNaFase() == false)
			fimJogo = true;
	}
}

void JogoEstado::verificarVitoriaJogo()
{
	switch (fase)
	{
	case 12:
		if (fasePrimeira->getTerminou())
		{
			if(multiplayer)
				estados->push(new VitoriaJogoEstado(estados, pComando, nomeJ, jogador1->getPontos(), true, true));
			else
				estados->push(new VitoriaJogoEstado(estados, pComando, nomeJ, jogador1->getPontos(), true, false));
		}
			
		break;
	case 1:
		if (fasePrimeira->getTerminou())
			vitoriaJogo = true;
		break;

	case 2:
		if (faseSegunda->getTerminou())
			vitoriaJogo = true;
		break;

	default:
		std::cout << "ERROR::JOGOESTADO::Fase não existente" << std::endl;
		break;
	}
	
}


void JogoEstado::updatePause()
{
	if (pause == true)
	{
		estados->push(new PauseEstado(estados, pComando));
	}
		
}

void JogoEstado::updateFimJogo()
{
	if (fimJogo == true)
		estados->push(new FimJogoEstado(estados, pComando));
}

void JogoEstado::updateVitoriaJogo()
{
	if (vitoriaJogo == true)
		estados->push(new VitoriaJogoEstado(estados, pComando, nomeJ, jogador1->getPontos(), false, false));
}

void JogoEstado::updateComando()
{
	updateDeltaTime();
	pComando->update(deltaTime);
	verificarPause();
}

void JogoEstado::update()
{
	updatePause();
	verificarFimJogo();
	verificarVitoriaJogo();
	updateFimJogo();
	updateVitoriaJogo();
	updateComando();

	switch (fase)
	{
	case 12:
	case 1:
		fasePrimeira->update();
		break;

	case 2:
		faseSegunda->update();
		break;

	default:
		std::cout << "ERROR::JOGOESTADO::UPDATE::Fase não existente" << std::endl;
		break;
	}
	
}

void JogoEstado::render()
{
	switch (fase)
	{
	case 12:
	case 1:
		fasePrimeira->renderFasePrimeira();
		break;

	case 2:
		faseSegunda->renderFaseSegunda();
		break;

	default:
		std::cout << "ERROR::JOGOESTADO::Fase não existente" << std::endl;
		break;
	}
	
}

void JogoEstado::salvar()
{
	std::ofstream gravador("./Carregamentos/ConfiguracoesFase.txt", std::ios::out);
	if (!gravador)
	{
		std::cout << "arquivo não pode ser aberto" << std::endl;
		fflush(stdin);
		return;
	}
	gravador
		<< nomeJ << " "
		<< fase << " "
		<< multiplayer << std::endl;
	gravador.close();

	switch (fase)
	{
	case 12:
	case 1:
		fasePrimeira->salvar();

		break;

	case 2:
		faseSegunda->salvar();
		break;

	default:
		std::cout << "ERROR::JOGOESTADO::Fase não existente" << std::endl;
		break;
	}
}

void JogoEstado::recuperar()
{
	switch (fase)
	{
	case 12:
	case 1:
		fasePrimeira->recuperar();

		break;

	case 2:
		faseSegunda->recuperar();
		break;

	default:
		std::cout << "ERROR::JOGOESTADO::Fase não existente" << std::endl;
	}
}