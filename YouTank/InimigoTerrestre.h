#pragma once
#include "Inimigo.h"
class InimigoTerrestre :
    public Inimigo
{
private:
    //private functions
    void initShape();
public:
    InimigoTerrestre();
    ~InimigoTerrestre();

   
    
};

