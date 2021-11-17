#include "stdafx.h"
#include "Background.h"

Background::Background(const char* file, float escala) :
	Ente()
{
	id = 403; // b4ckgr0und, 3 pois é sprite
	setTexture(file, escala);
}

Background::~Background()
{
}

void Background::renderBackground()
{
	pGraphic->getWindow()->draw(sprite);
}


