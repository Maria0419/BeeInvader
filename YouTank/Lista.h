#pragma once
#include "stdafx.h"
#include "Elemento.h"


template<class TIPO>
class Lista
{
private:
	Elemento<TIPO>* pPrimeiro;
	Elemento<TIPO>* pAtual;
	int tamanho;

public:
	Lista();
	~Lista();
	void inicializa();
	void limpaLista();

	void incluaElemento(Elemento<TIPO>* pElemento);
	void incluaInfo(TIPO* pInfo);
	void deletaElemento(Elemento<TIPO>* pElemento);
	void deletaInfo(TIPO* pInfo);

	Elemento<TIPO>* getPrimeiro();
	Elemento<TIPO>* getAtual();

	int getTamanho();
};

template<class TIPO>
Lista<TIPO>::Lista()
{
	inicializa();
}

template<class TIPO>
Lista<TIPO>::~Lista()
{
	limpaLista();
}

template<class TIPO>
void Lista<TIPO>::inicializa()
{
	tamanho = 0;
	pPrimeiro = NULL;
	pAtual = NULL;
}

template<class TIPO>
void Lista<TIPO>::limpaLista()
{
	Elemento<TIPO>* pAux = pPrimeiro;
	while (pPrimeiro != NULL)
	{
		pPrimeiro = pPrimeiro->getProximo();
		delete (pAux);
		pAux = pPrimeiro;
	}
	pAtual = NULL;
}

template<class TIPO>
void Lista<TIPO>::incluaElemento(Elemento<TIPO>* pElemento)
{
	if (pElemento != NULL)
	{
		if (pPrimeiro == NULL)
		{
			pPrimeiro = pElemento;
			pAtual = pPrimeiro;
		}
		else
		{
			pElemento->setAnterior(pAtual);
			pAtual->setProximo(pElemento);
			pAtual = pAtual->getProximo();
		}
	}
	else
	{
		std::cout << "Erro, elemento nulo na lista?" << std::endl;
	}
}

template<class TIPO>
void Lista<TIPO>::incluaInfo(TIPO* pInfo)
{
	if (pInfo != NULL)
	{
		Elemento<TIPO>* pElemento = new Elemento<TIPO>();
		pElemento->setInfo(pInfo);
		incluaElemento(pElemento);
		tamanho++;
	}
	else
	{
		std::cout << "Erro, elemento nulo na lista?" << std::endl;
	}
}

template<class TIPO>
inline void Lista<TIPO>::deletaElemento(Elemento<TIPO>* pElemento)
{
}

template<class TIPO>
void Lista<TIPO>::deletaInfo(TIPO* pElemento)
{
	bool deleted = false;
	Elemento<TIPO>* pAux = pPrimeiro;
	Elemento<TIPO>* pProximo = NULL;
	Elemento<TIPO>* pAnterior = NULL;
	while (pAux != NULL && !deleted)
	{
		pProximo = pAux->getProximo();
		if (pAux->getInfo() == pElemento)
		{
			if (pAnterior != NULL && pProximo != NULL)
				pAnterior->setProximo(pProximo);
			else if (pAnterior != NULL && pProximo == NULL)
			{
				pAnterior->setProximo(NULL);
				pAtual = pAnterior;
			}
			else if (pAnterior == NULL && pProximo != NULL)
			{
				pPrimeiro = pProximo;
				pPrimeiro->setAnterior(NULL);
			}
			else
				pPrimeiro = NULL;
			pAux->deletaInfo();
			delete pAux;
			tamanho--;
			deleted = true;
		}
		else
		{
			pAnterior = pAux;
			pAux = pAux->getProximo();
		}
	}
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getPrimeiro()
{
	return pPrimeiro;
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getAtual()
{
	return pAtual;
}

template<class TIPO>
inline int Lista<TIPO>::getTamanho()
{
	return tamanho;
}
