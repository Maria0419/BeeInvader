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
	void deletaInfo(TIPO* pInfo);
	Elemento<TIPO>* procuraElemento(TIPO* pInfo);

	Elemento<TIPO>* getPrimeiro();
	Elemento<TIPO>* getAtual();
	TIPO* operator[](int i);

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
		delete pAux->getInfo();
		delete (pAux);
		pAux = pPrimeiro;
	}
	pAtual = NULL;
}

template<class TIPO>
void Lista<TIPO>::incluaElemento(Elemento<TIPO>* pElemento)
{
	if (pElemento)
	{
		if (pPrimeiro == NULL)
		{
			pPrimeiro = pElemento;
			pAtual = pElemento;
			pPrimeiro->setAnterior(NULL);
			pAtual->setProximo(NULL);
		}
		else
		{
			pAtual->setProximo(pElemento);
			pElemento->setAnterior(pAtual);
			pAtual = pAtual->getProximo();
			pAtual->setProximo(NULL);
		}
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
void Lista<TIPO>::deletaInfo(TIPO* pElemento)
{
	Elemento<TIPO>* pAux = procuraElemento(pElemento);
	if (pAux->getAnterior() != NULL && pAux->getProximo() != NULL)
	{
		pAux->getAnterior()->setProximo(pAux->getProximo());
		pAux->getProximo()->setAnterior(pAux->getAnterior());
	}
	else if (pAux->getAnterior() == NULL && pAux->getProximo() != NULL)
	{
		pPrimeiro = pAux->getProximo();
		pPrimeiro->setAnterior(NULL);
	}
	else if (pAux->getProximo() == NULL && pAux->getAnterior() != NULL)
	{
		pAtual = pAux->getAnterior();
		pAtual->setProximo(NULL);
	}
	else
		pPrimeiro = NULL;
	pAux->deletaInfo();
	delete pAux;
	pAux = NULL;
	tamanho--;
}

template<class TIPO>
inline Elemento<TIPO>* Lista<TIPO>::procuraElemento(TIPO* pInfo)
{
	Elemento<TIPO>* pAux = pPrimeiro;
	while (pAux != NULL && pAux->getInfo() != pInfo)
	{
		pAux = pAux->getProximo();
	}
	return pAux;
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
inline TIPO* Lista<TIPO>::operator[](int i)
{
	Elemento<TIPO>* pAux = pPrimeiro;
	while (pAux != NULL && i > 0)
	{
		pAux = pAux->getProximo();
		i--;
	}
	return pAux->getInfo();
}

template<class TIPO>
inline int Lista<TIPO>::getTamanho()
{
	return tamanho;
}
