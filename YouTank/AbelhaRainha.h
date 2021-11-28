#pragma once
#include "BarraVida.h"
#include "Ferrao.h"
#include "FadaCaida.h"
#include "Inimigo.h"
#include "Abelha.h"

namespace Inimigos
{

	class AbelhaRainha :
		public Inimigo
	{
	private:
		ElementosVisuais::BarraVida barraVida;
		float originX;
		float x;
		float y;
		unsigned int curaTimer;
		unsigned int curaTimerMAX;
		unsigned int ferraoTimer;
		unsigned int ferraoTimerMAX;

		float angulo;
		float anguloMAX;
		Ferrao* pFerrao;
		Abelha* pAbelha;
		Jogadores::FadaCaida* pFadaCaida;

		void initTimers();
		void initShape();

	public:
		AbelhaRainha();
		~AbelhaRainha();
		const bool emFuria();
		void curaVida();

		void update();
		void updateAtaque();
		void updateMovimento();
		void updateTaVivo();
		void renderAbelhaRainha();

		void salvar();
		void recuperar();

		void setFadaCaidaAlvo(Jogadores::FadaCaida* pJ);

		const bool getExisteNaFase() const;

	};

}