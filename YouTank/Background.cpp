#include "stdafx.h"
#include "Global.h"
#include "Background.h"
using namespace ElementosVisuais;

Background::Background()
{
}

Background::Background(const char* file) :
	Ente()
{
	id = ID_BACKGROUND; 

	setSize(1280.f, 720.f);
	setTexture(file);
}

Background::~Background()
{
}


