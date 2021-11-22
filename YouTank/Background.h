#pragma once
#include "Ente.h"

class Background :
    public Ente
{
private:

public:
    Background();
    Background(const char* file, float escala = 1.f);
    ~Background();

    void renderBackground();
};

