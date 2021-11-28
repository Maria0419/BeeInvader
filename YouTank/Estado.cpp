#include "stdafx.h"
#include "Estado.h"


Estado::Estado(std::stack<Estado*>* estado, GerenciadorComando* pGC, short id) :
	sair(false),
	pause(false),
	fimJogo(false),
	vitoriaJogo(false),
	irMenu(false),
	terminarEstado(false),
	salvarPontos(false),
	salvarFase(false),
	estadoID(id),
	pComando(pGC)
{
	estados = estado;
}

Estado::~Estado()
{
}

void Estado::setPause(bool p)
{
	pause = p;
}

void Estado::setNome(std::string nome)
{
	nomeJ = nome;
}

void Estado::setPontos(int i)
{
}

const bool Estado::getSair() const
{
	return sair;
}

const bool Estado::getPause() const
{
	return pause;
}

const bool Estado::getFimJogo() const
{
	return fimJogo;
}

const bool Estado::getVitoriaJogo() const
{
	return vitoriaJogo;
}

const bool Estado::getIrMenu() const
{
	return irMenu;
}

const bool Estado::getTerminarEstado() const
{
	return terminarEstado;
}

const bool Estado::getSalvarFase() const
{
	return salvarFase;
}

const std::string Estado::getNome() const
{
	return std::string();
}

void Estado::verificarPause()
{
	if (pComando->getPause() == true)
		pause = true;	
}

void Estado::verificarIrMenu()
{

}

void Estado::salvar()
{
}

void Estado::recuperar()
{
}
