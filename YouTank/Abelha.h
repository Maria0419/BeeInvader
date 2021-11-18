#pragma once
#include "Inimigo.h"
class Abelha :
    public Inimigo
{
private:
    //private functions
    void initShape();
public:
    Abelha(float dir_x, float dir_y);
    Abelha();
    ~Abelha();

    float getDirecao_x();
    float getDirecao_y();

    void setShowing(bool x);
    const bool getShowing() const;
    
};

