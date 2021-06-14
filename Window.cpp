#include "Window.h"

void Window::SetActive(bool state)
{
	for (auto object : elements)
	{
		object->IsVisible = state;	
	}
}
