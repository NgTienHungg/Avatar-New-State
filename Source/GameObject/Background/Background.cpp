#include "Background.h"

Background::Background()
{
}

Background::~Background()
{
	for (Layer* layer : m_list_layer) {
		if (layer != nullptr) {
			delete layer;
			layer = nullptr;
		}
	}
	m_list_layer.clear();
}

void Background::initBackground()
{
	Layer* layer;
	layer = new Layer();
	layer->initLayer("sky", 0.f);
	m_list_layer.push_back(layer);

	layer = new Layer();
	layer->initLayer("moutain_1", 20.f);
	m_list_layer.push_back(layer);

	layer = new Layer();
	layer->initLayer("moutain_2", 20.f);
	m_list_layer.push_back(layer);

	layer = new Layer();
	layer->initLayer("pine", 30.f);
	m_list_layer.push_back(layer);

	layer = new Layer();
	layer->initLayer("cloud_1", 30.f);
	m_list_layer.push_back(layer);

	layer = new Layer();
	layer->initLayer( "cloud_2", 40.f);
	m_list_layer.push_back(layer);

	layer = new Layer();
	layer->initLayer("cloud_3", 50.f);
	m_list_layer.push_back(layer);

	layer = new Layer();
	layer->initLayer("cloud_4", 60.f);
	m_list_layer.push_back(layer);
}

void Background::updateBackground(float deltaTime)
{
	for (Layer* layer : m_list_layer) {
		layer->updateLayer(deltaTime);
	}
}

void Background::renderBackground(RenderWindow* window)
{
	for (Layer* layer : m_list_layer) {
		layer->renderLayer(window);
	}
}