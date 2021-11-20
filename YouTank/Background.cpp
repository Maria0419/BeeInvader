#include "stdafx.h"
#include "Background.h"
#include "Global.h"

Background::Background(const char* file, float escala) :
	Ente()
{
	id = ID_BACKGROUND; 
	setTexture(file, escala);
}

Background::~Background()
{
}

void Background::renderBackground()
{
	pGraphic->getWindow()->draw(sprite);
}


