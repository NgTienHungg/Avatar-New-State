#pragma once
#include "GSBase.h"

class GSRecord : public GSBase
{
private:
	Background* m_background;
	RectangleShape* m_frame;
	RectangleShape* m_headline;

	RectangleShape* m_logo_1;
	Text* m_name_1;
	Text* m_level_1;
	Text* m_coin_1;

	RectangleShape* m_logo_2;
	Text* m_name_2;
	Text* m_level_2;
	Text* m_coin_2;

	RectangleShape* m_logo_3;
	Text* m_name_3;
	Text* m_level_3;
	Text* m_coin_3;

	Button* m_button_back;
	Text* m_text_back;

	vector<pair<string, pair<int, int>>> m_list_user;

	void initDataRecord();
	void initBoard();
	void initRank1();
	void initRank2();
	void initRank3();
	void initButtonHome();

	void renderRank1(RenderWindow* window);
	void renderRank2(RenderWindow* window);
	void renderRank3(RenderWindow* window);

public:
	GSRecord();
	~GSRecord();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};