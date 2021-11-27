#pragma once
#include "Entidade.h"
class Obstaculo :
    public Entidade
{
protected:
    float tamX;
    float tamY;

public:
    Obstaculo(int i, float tam_x, float tam_y);
    ~Obstaculo();

    void salvar();
};

