#pragma once
#include "GSBase.h"

class GSSelectMap : public GSBase
{
private:
	Background* m_background;
	RectangleShape* m_headline;
	RectangleShape* m_frame;

	Button* m_button_back;
	Text* m_text_back;

	vector<Button*> m_list_map;
	vector<Text*> m_list_text;

	int m_count_map;

	void initBoard();
	void initButtonBack();
	void initListMap();

	void updateListMap(float delta_time);

public:
	GSSelectMap();
	~GSSelectMap();

	GameState getTypeState();
	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};