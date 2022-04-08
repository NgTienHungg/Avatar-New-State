#pragma once
#include "GSBase.h"

class GSPlay : public GSBase
{
private:
	Sprite* m_background;
	Match* m_match;
	Character* m_player;
	Character* m_enemy;
	Button* m_button_pause;

	RectangleShape* m_board_coin;
	Text* m_text_coin;
	RectangleShape* m_board_time;
	Text* m_text_time;
	Text* m_notify;

	int m_sword_point;
	int m_coin_point;
	float m_damage;

	float m_time_play;
	float m_current_time_play;

	float m_time_perform;
	float m_current_time_perform;

	bool m_is_intro;
	bool m_is_playing;
	bool m_is_started_play;
	bool m_is_performing;
	bool m_is_player_turn;

	bool m_is_player_win;
	bool m_is_stop_game_play;
	bool m_is_continue_next_turn;

	void initBoardCoin();
	void initBoardTime();
	void initButtonPause();
	void initNotify();

	void introState(float delta_time);
	void handlePoint();
	void performAnimation(float delta_time);
	void handleWinLose(float delta_time);
	void handleTimePlay(float delta_time);
	void handleNotify();

public:
	GSPlay();
	~GSPlay();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};