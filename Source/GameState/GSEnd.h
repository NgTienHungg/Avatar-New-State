#pragma once
#include "GSBase.h"

class GSEnd : public GSBase
{
private:
	Sprite* m_background;
	RectangleShape* m_frame;
	RectangleShape* m_headline;
	Text* m_title;

	Text* m_id;
	Text* m_level;
	Text* m_coin;

	Text* m_name;
	Text* m_change_level;
	Text* m_change_coin;

	Button* m_button_home;
	
	void initBoard();
	void initTextName();
	void initTextLevel();
	void initTextCoin();
	void initButton();
	void updateUser();

public:
	GSEnd();
	~GSEnd();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};