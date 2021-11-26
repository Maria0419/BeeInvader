#pragma once
#include "Ente.h"
namespace ElementosVisuais
{

class Background :
    public Ente
{
private:
    
public:
    Background();
    Background(const char* file);
    ~Background();
};

}