#pragma once
#include "Personagem.h"
#include "Orbe.h"
#include "BarraVida.h"

class FadaCaida :
    public Personagem
{
private:

    BarraVida barraVida;
    Orbe* pOrbe;
    bool colisaoBot;

    //private functions
    void initShape();

public:
    FadaCaida();
    ~FadaCaida();

    void setOlhaEsquerda(bool x);
    const bool olhandoEsquerda() const;

    void setDirecao_x(float dir_x);
    void setDirecao_y(float dir_y);
    
    void naColisao();
    void ataca(float dir_x, float dir_y);

    void updateAnimacao();
    void updateTaVivo();
    
    void update();

    void renderBarraVida();    

    const bool getColisaoBot() const;
    const bool getExisteNaFase() const;
   
};

