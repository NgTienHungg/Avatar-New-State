#pragma once
#include "Piece.h"
#include <vector>
using namespace std;

class Match
{
private:
	RectangleShape* m_frame;
	RectangleShape* m_board;
	Piece* m_grid[8][8];
	vector<float> m_points;

	Vector2f m_root_board; // top left point of board
	Vector2f m_size_piece; // size of piece
	float m_click_time; // handle mouse click event
	int m_c1, m_r1, m_c2, m_r2; // 1: selected position, 2: swap position

	bool m_has_selection; // check has selection
	bool m_is_swapping; // check to reverse swap if not valid
	bool m_is_moving; // check board doenn't stop
	bool m_is_continue_next_turn;
	bool m_is_finished_turn;
	bool m_is_match_ready;

	int getScore();
	int randomPiece(int r, int c);
	void swapPiece(Piece* a, Piece* b);
	bool isNextTo(int r, int c);

	void initBoard();
	void initGridPiece();

	void introMatch(float delta_time);
	void checkView(float delta_time);
	void checkClick(float delta_time);
	void moveAnimation(float delta_time);
	void findMatch(float delta_time);
	void checkReverseSwap(float delta_time);
	void deleteAnimation(float delta_time);
	void updateBoard(float delta_time);

	/* Bot */
	struct Option
	{
		Vector2i m_pos_1; // selected position
		Vector2i m_pos_2; // swap position
		int m_score; // chuỗi dài nhất match được
		int m_priority; //độ ưu tiên item ăn được => sort

		Option(Vector2i pos_1, Vector2i pos_2, int score, int priority) {
			m_pos_1 = pos_1;
			m_pos_2 = pos_2;
			m_score = score;
			m_priority = priority;
		}
	};

	vector<Option> m_option_list;
	float m_time_bot_play;
	bool m_is_bot_playing;

	void searchAllOptions();
	void botPlaying(float delta_time);

public:
	Match();
	~Match();

	bool hasPoint();
	vector<float> getPoints();
	void resetPoints();
	void resetTurn();

	Vector2f getSize();
	Vector2f getPosition();

	bool isMoving();
	bool isMatchReady();
	bool isFinishedTurn();
	bool isContinueNextTurn();

	void initMatch();
	void updateMatch(float delta_time);
	void updateBot(float delta_time);
	void renderMatch(RenderWindow* window);
};