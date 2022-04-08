#pragma once
#include "../../GameManager/Application.h"
#include "../../GameManager/DataManager.h"

enum class PieceType
{
	HEART = 0,
	MANA,
	POISON,
	SWORD,
	ARMOR,
	COIN
};

class Piece : public RectangleShape
{
private:
	PieceType m_type;
	float m_point;
	bool m_can_match;
	bool m_is_selected;

	Vector2f m_root, m_size;
	float m_x, m_y; // coordinate of piece
	int m_r, m_c; // row, column
	int m_alpha;
	float m_velocity;

public:
	Piece();
	~Piece();

	int getType();
	float getPoint();

	void setCanMatch(bool match);
	bool canMatch();

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void setR(int r);
	int getR();

	void setC(int c);
	int getC();

	void setAlpha(int alpha);
	int getAlpha();

	void setVelocity(float velocity);
	float getVelocity();

	bool isContained();

	void setNormalMode();
	void setViewMode();
	void setSelectionMode();
	void setCancelSelectionMode();
	void setBotSelectionMode();

	void resetPiece(int type);
	void initPiece(int type, int row, int column, Vector2f root, Vector2f size);
	void updatePiece(float deltaTime);
	void renderPiece(RenderWindow* window);
};