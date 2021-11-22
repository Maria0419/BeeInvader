#include "stdafx.h"
#include "Background.h"
#include "Global.h"

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


