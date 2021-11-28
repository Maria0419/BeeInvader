#pragma once
#include "Ente.h"
namespace ElementosVisuais
{

class PlanoFundo :
    public Ente
{
private:
    
public:
    PlanoFundo();
    PlanoFundo(const char* file);
    ~PlanoFundo();
};

}