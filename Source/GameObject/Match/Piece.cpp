#include "Piece.h"

Piece::Piece()
{
	m_type = PieceType::COIN;
	m_point = 0.f;
	m_x = m_y = 0;
	m_r = m_c = 0;
	m_alpha = 255;
	m_can_match = 0;
	m_is_selected = false;
	m_velocity = 0.f;
}

Piece::~Piece()
{
}

void Piece::setCanMatch(bool match)
{
	m_can_match = match;
}

bool Piece::canMatch()
{
	return m_can_match;
}

void Piece::setX(float x)
{
	m_x = x;
}

float Piece::getX()
{
	return m_x;
}

void Piece::setY(float y)
{
	m_y = y;
}

float Piece::getY()
{
	return m_y;
}

void Piece::setR(int r)
{
	m_r = r;
}

int Piece::getR()
{
	return m_r;
}

void Piece::setC(int c)
{
	m_c = c;
}

int Piece::getC()
{
	return m_c;
}

void Piece::setAlpha(int alpha)
{
	m_alpha = alpha;
}

int Piece::getAlpha()
{
	return m_alpha;
}

void Piece::setVelocity(float velocity)
{
	m_velocity = velocity;
}

float Piece::getVelocity()
{
	return m_velocity;
}

int Piece::getType()
{
	switch (m_type)
	{
	case PieceType::HEART:
		return 0;
	case PieceType::MANA:
		return 1;
	case PieceType::POISON:
		return 2;
	case PieceType::SWORD:
		return 3;
	case PieceType::ARMOR:
		return 4;
	case PieceType::COIN:
		return 5;
	}
	return 0;
}

float Piece::getPoint()
{
	return m_point;
}

bool Piece::isContained()
{
	return (this->getGlobalBounds().contains((Vector2f)Mouse::getPosition(*APP->getWindow())));
}

void Piece::setNormalMode()
{
	if (m_is_selected) return;
	this->setOutlineColor(Color::Transparent);
}

void Piece::setViewMode()
{
	if (m_is_selected) return;
	this->setOutlineColor(Color::Cyan);
}

void Piece::setSelectionMode()
{
	m_is_selected = true;
	this->setOutlineColor(Color::Green);
}

void Piece::setCancelSelectionMode()
{
	m_is_selected = false;
	this->setNormalMode();
}

void Piece::setBotSelectionMode()
{
	m_is_selected = true;
	this->setOutlineColor(Color::Red);
}

void Piece::resetPiece(int type)
{
	string path = "GUI/Piece/";
	switch (type)
	{
	case 0:
		m_type = PieceType::HEART;
		setTexture(DATA->getTexture(path + "heart"));
		m_point = 5.f;
		break;
	case 1:
		m_type = PieceType::MANA;
		setTexture(DATA->getTexture(path + "mana"));
		m_point = 7.f;
		break;
	case 2:
		m_type = PieceType::POISON;
		setTexture(DATA->getTexture(path + "poison"));
		m_point = 10.f;
		break;
	case 3:
		m_type = PieceType::SWORD;
		setTexture(DATA->getTexture(path + "sword"));
		m_point = 1.f;
		break;
	case 4:
		m_type = PieceType::ARMOR;
		setTexture(DATA->getTexture(path + "armor"));
		m_point = 7.f;
		break;
	case 5:
		m_type = PieceType::COIN;
		setTexture(DATA->getTexture(path + "coin"));
		m_point = 1.f;
		break;
	default:
		break;
	}

	m_can_match = false;
	m_alpha = 255;
}

void Piece::initPiece(int type, int row, int column, Vector2f root, Vector2f size)
{
	m_root = root, m_size = size;
	m_r = row, m_c = column;
	m_x = m_size.x * (m_c + 0.5f);
	m_y = m_size.y * (m_r + 0.5f);

	this->resetPiece(type);
	this->setSize(Vector2f(55.f, 55.f));
	this->setOrigin(this->getSize() / 2.f);
	this->setOutlineThickness(5.f);
	this->setPosition(Vector2f(m_root.x + m_x, m_root.y + m_y));
}

void Piece::updatePiece(float deltaTime)
{
	this->setPosition(Vector2f(m_root.x + m_x, m_root.y + m_y));
	this->setFillColor(Color(255, 255, 255, m_alpha));
}

void Piece::renderPiece(RenderWindow* window)
{
	window->draw(*this);
}