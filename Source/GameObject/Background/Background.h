#pragma once
#include "Layer.h"
#include <list>

using namespace std;

class Background
{
private:
	list<Layer*> m_list_layer;

public:
	Background();
	~Background();

	void initBackground();
	void updateBackground(float deltaTime);
	void renderBackground(RenderWindow* window);
};