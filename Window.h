#pragma once
#include "GlobalResource.h"
#include "Drawable.h"

using std::vector;

class Window
{
public:
	vector<Drawable*> elements;

	void SetActive(bool state);
};

