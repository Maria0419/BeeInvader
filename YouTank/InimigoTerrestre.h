#pragma once
#include "Inimigo.h"
class InimigoTerrestre :
    public Inimigo
{
private:
    //private functions
    void initShape();
public:
    InimigoTerrestre(float dir_x, float dir_y);
    InimigoTerrestre();
    ~InimigoTerrestre();

    float getDirecao_x();
    float getDirecao_y();

    void setShowing(bool x);
    const bool getShowing() const;
    
};

