#pragma once
#include "GSBase.h"

class GSHelp : public GSBase
{
private:
	Background* m_background;
	RectangleShape* m_frame;
	Text* m_title;
	int m_current_page;

	Button* m_button_left;
	Button* m_button_right;
	Button* m_button_back;
	Text* m_text_back;

	// page 1
	RectangleShape* m_item_sword;
	RectangleShape* m_item_heart;
	RectangleShape* m_item_mana;
	RectangleShape* m_item_armor;
	RectangleShape* m_item_poison;
	RectangleShape* m_item_coin;

	Text* m_text_sword;
	Text* m_text_heart;
	Text* m_text_mana;
	Text* m_text_armor;
	Text* m_text_poison;
	Text* m_text_coin;

	// page 2
	RectangleShape* m_bar_mana;
	RectangleShape* m_bar_shield;
	Text* m_text_mana_2;
	Text* m_text_shield;
	Text* m_text_continue;

	// page 3
	Text* m_text_if_win;
	Text* m_text_if_lose;
	Text* m_text_level_and_coin;
	Text* m_note;

	void initBoard();
	void initPage1();
	void initPage2();
	void initPage3();
	void initButton();

	void updateButton(float delta_time);

	void renderPage1(RenderWindow* window);
	void renderPage2(RenderWindow* window);
	void renderPage3(RenderWindow* window);

public:
	GSHelp();
	~GSHelp();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};