#pragma once
#include "Ente.h"
class Background :
    public Ente
{
private:

public:
    Background(const char* file, float escala);
    ~Background();

    void renderBackground();
};

