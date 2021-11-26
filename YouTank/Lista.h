#pragma once
#include "stdafx.h"

template<class TL>
class Lista
{
	template<class TE>
	class Elemento
	{
	private:
		Elemento<TE>* pProximo;
		Elemento<TE>* pAnterior;
		TE* pInfo;

	public:
		Elemento() {
			pProximo = NULL;
			pAnterior = NULL;
			pInfo = NULL;
		}
		~Elemento() {
			pProximo = NULL;
			pAnterior = NULL;
			pInfo = NULL;
		}

		void setProximo(Elemento<TE>* pp) {
			pProximo = pp;
		}
		Elemento<TE>* getProximo() {
			return pProximo;
		}

		void setAnterior(Elemento<TE>* pa) {
			pAnterior = pa;
		}
		Elemento<TE>* getAnterior() {
			return pAnterior;
		}

		void setInfo(TE* pi) {
			pInfo = pi;
		}
		TE* getInfo() {
			return pInfo;
		}

		void deletaInfo() {
			pInfo = NULL;
		}

	};

private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pAtual;
	int tamanho;

public:
	Lista();
	~Lista();
	void inicializa();
	void limpaLista();

	void incluaElemento(Elemento<TL>* pElemento);
	void incluaInfo(TL* pInfo);
	void deletaInfo(TL* pInfo);
	Elemento<TL>* procuraElemento(TL* pInfo) {
		Elemento<TL>* pAux = pPrimeiro;
		while (pAux != NULL && pAux->getInfo() != pInfo)
		{
			pAux = pAux->getProximo();
		}
		return pAux;
	}

	Elemento<TL>* getPrimeiro() {
		return pPrimeiro;
	}
	Elemento<TL>* getAtual() {
		return pAtual;
	}
	TL* operator[](int i);

	int getTamanho();
};



template<class TL>
Lista<TL>::Lista()
{
	inicializa();
}

template<class TL>
Lista<TL>::~Lista()
{
	limpaLista();
}

template<class TL>
void Lista<TL>::inicializa()
{
	tamanho = 0;
	pPrimeiro = NULL;
	pAtual = NULL;
}

template<class TL>
void Lista<TL>::limpaLista()
{
	Elemento<TL>* pAux = pPrimeiro;
	while (pPrimeiro != NULL)
	{
		pPrimeiro = pPrimeiro->getProximo();
		delete pAux->getInfo();
		delete (pAux);
		pAux = pPrimeiro;
	}
	pAtual = NULL;
}

template<class TL>
void Lista<TL>::incluaElemento(Elemento<TL>* pElemento)
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

template<class TL>
void Lista<TL>::incluaInfo(TL* pInfo)
{
	if (pInfo != NULL)
	{
		Elemento<TL>* pElemento = new Elemento<TL>();
		pElemento->setInfo(pInfo);
		incluaElemento(pElemento);
		tamanho++;
	}
	else
	{
		std::cout << "Erro, elemento nulo na lista?" << std::endl;
	}
}

template<class TL>
void Lista<TL>::deletaInfo(TL* pElemento)
{
	Elemento<TL>* pAux = procuraElemento(pElemento);
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


template<class TL>
inline TL* Lista<TL>::operator[](int i)
{
	Elemento<TL>* pAux = pPrimeiro;
	while (pAux != NULL && i > 0)
	{
		pAux = pAux->getProximo();
		i--;
	}
	return pAux->getInfo();
}

template<class TL>
inline int Lista<TL>::getTamanho()
{
	return tamanho;
}
