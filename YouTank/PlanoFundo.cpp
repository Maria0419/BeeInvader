#include "stdafx.h"
#include "Global.h"
#include "PlanoFundo.h"
using namespace ElementosVisuais;

PlanoFundo::PlanoFundo()
{
}

PlanoFundo::PlanoFundo(const char* file) :
	Ente()
{
	id = ID_BACKGROUND; 

	setSize(1280.f, 720.f);
	setTexture(file);
}

PlanoFundo::~PlanoFundo()
{
}


