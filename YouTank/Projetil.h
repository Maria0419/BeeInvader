#pragma once
#include "Entidade.h"

class Projetil :
    public Entidade
{
private:
    
protected:

public:
    Projetil(int i);
    ~Projetil();

    float getDirecao_x();
    float getDirecao_y();

    void setShowing(bool x);
    const bool getShowing() const;

    void setPodeMatar(bool x);
    const bool getPodeMatar() const;
};

