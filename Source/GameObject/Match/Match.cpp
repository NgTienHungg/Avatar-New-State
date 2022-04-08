#include "Match.h"
#include <cmath>

Match::Match()
{
	m_frame = new RectangleShape();
	m_board = new RectangleShape();
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			m_grid[i][j] = new Piece();
		}
	}

	m_points.resize(6, 0);
	m_r1 = m_c1 = m_r2 = m_c2 = 0;
	m_click_time = 0.f;

	m_has_selection = false;
	m_is_moving = false;
	m_is_swapping = false;
	m_is_continue_next_turn = false;
	m_is_finished_turn = false;
	m_is_match_ready = false;

	m_is_bot_playing = false;
	m_time_bot_play = 0.f;
}

Match::~Match()
{
	if (m_frame != nullptr) {
		delete m_frame;
	}
	if (m_board != nullptr) {
		delete m_board;
	}
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (m_grid[i][j] != nullptr)
				delete m_grid[i][j];
		}
	}
}

int Match::getScore()
{
	int score = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (m_grid[i][j]->canMatch() == true) {
				score++;
			}
		}
	}
	return score;
}

int Match::randomPiece(int r, int c)
{
	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };
	vector<int> v;
	for (int k = 0; k < 4; ++k) {
		int i = r + dr[k];
		int j = c + dc[k];
		if (i >= 0 && i < 8 && j >= 0 && j < 8 && !m_grid[i][j]->canMatch()) {
			v.push_back(m_grid[i][j]->getType());
		}
	}
	bool random = rand() % 3;
	if (random == 0 && !v.empty()) {
		// 25% sẽ theo các ô bên cạnh
		return v[rand() % v.size()];
	}
	return rand() % 6;
}

void Match::swapPiece(Piece* a, Piece* b)
{
	int row = a->getR();
	int col = a->getC();

	a->setR(b->getR());
	a->setC(b->getC());

	b->setR(row);
	b->setC(col);

	m_grid[a->getR()][a->getC()] = a;
	m_grid[b->getR()][b->getC()] = b;
}

bool Match::isNextTo(int r, int c)
{
	// check ? next to the piece was selected
	return ((r + 1 == m_r1 && c == m_c1)
		|| (r - 1 == m_r1 && c == m_c1)
		|| (r == m_r1 && c + 1 == m_c1)
		|| (r == m_r1 && c - 1 == m_c1));
}

bool Match::hasPoint()
{
	for (int i = 0; i < (int)m_points.size(); ++i) {
		if (m_points[i] != 0) {
			return true;
		}
	}
	return false;
}

vector<float> Match::getPoints()
{
	return m_points;
}

void Match::resetPoints()
{
	m_points.clear();
	m_points.resize(6, 0);
}

bool Match::isFinishedTurn()
{
	return m_is_finished_turn;
}

bool Match::isContinueNextTurn()
{
	return m_is_continue_next_turn;
}

bool Match::isMoving()
{
	return m_is_moving;
}

bool Match::isMatchReady()
{
	return m_is_match_ready;
}

void Match::resetTurn()
{
	m_is_bot_playing = false;
	m_is_finished_turn = false;
	m_is_continue_next_turn = false;
	m_time_bot_play = 0.f;
}

Vector2f Match::getSize()
{
	return m_frame->getSize();
}

Vector2f Match::getPosition()
{
	return m_frame->getPosition();
}

/*-----------------------------------------------------------------------*/

void Match::initBoard()
{
	// outline thickness frame = 30.f
	m_frame->setTexture(DATA->getTexture("GUI/Frame/gameplay"));
	m_frame->setSize(Vector2f(700.f, 700.f));
	m_frame->setPosition((ScreenWidth - m_frame->getSize().x) / 2.f, 0.f);

	m_board->setTexture(DATA->getTexture("Background/board"));
	m_board->setSize(Vector2f(640.f, 640.f));
	m_board->setPosition((ScreenWidth - m_board->getSize().x) / 2.f, 30.f);

	m_root_board = m_board->getPosition();
	m_size_piece = m_board->getSize() / 8.f;
}

void Match::initGridPiece()
{
	// gen
	srand((unsigned int)time(0));
	int count_sword = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (count_sword < 10) {
				int random = rand() % 4;
				// custom rate sword piece
				if (random == 0) {
					m_grid[i][j]->initPiece(3, i, j, m_root_board, m_size_piece);
					m_grid[i][j]->setNormalMode();
					continue;
				}
			}
			m_grid[i][j]->initPiece(rand() % 6, i, j, m_root_board, m_size_piece);
			m_grid[i][j]->setNormalMode();
		}
	}

	// delete match
	while (true) {
		this->findMatch(0.f);
		if (this->getScore() == 0) {
			break;
		}
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (m_grid[i][j]->canMatch()) {
					m_grid[i][j]->resetPiece(randomPiece(i, j));
				}
			}
		}
	}
	this->resetTurn();

	// intro
	m_is_match_ready = false;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			m_grid[i][j]->setAlpha(0);
		}
	}
}

void Match::introMatch(float delta_time)
{
	for (int i = 0; i < 8 * 2; ++i) {
		if (i == 8) continue;
		if (i < 8) {
			if (m_grid[i][0]->getAlpha() < 255) {
				int alpha = m_grid[i][0]->getAlpha();
				for (int j = i; j >= 0; --j) {
					m_grid[j][i - j]->setAlpha(alpha + 17);
				}
				break;
			}
		}
		else {
			int column = i - 8;
			if (m_grid[7][column]->getAlpha() < 255) {
				int alpha = m_grid[7][column]->getAlpha();
				for (int j = 7; j >= column; --j) {
					m_grid[j][column + 7 - j]->setAlpha(alpha + 17);
				}
				break;
			}
		}
	}

	if (m_grid[7][7]->getAlpha() == 255) {
		m_is_match_ready = true;
	}
	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			m_grid[i][j]->updatePiece(delta_time);
		}
	}
}

void Match::checkView(float delta_time)
{
	if (!m_is_moving) {
		if (m_has_selection) {
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					if (i == m_r1 && j == m_c1) {
						continue;
					}
					else if (m_grid[i][j]->isContained() && isNextTo(i, j)) {
						m_grid[i][j]->setViewMode();
					}
					else {
						m_grid[i][j]->setNormalMode();
					}
				}
			}
		}
		else {
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					if (m_grid[i][j]->isContained()) {
						m_grid[i][j]->setViewMode();
					}
					else {
						m_grid[i][j]->setNormalMode();
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				m_grid[i][j]->setNormalMode();
			}
		}
	}
}

void Match::checkClick(float delta_time)
{
	if (!m_is_moving && Mouse::isButtonPressed(Mouse::Left) && m_board->getGlobalBounds().contains((Vector2f)Mouse::getPosition(*APP->getWindow()))) {
		m_click_time += delta_time;
		if (m_click_time >= ClickTime) {
			DATA->playSound("click");
			m_click_time = 0.f;
			if (!m_has_selection) {
				//todo select piece
				Vector2f pos = (Vector2f)Mouse::getPosition(*APP->getWindow()) - m_root_board;
				m_c1 = int(pos.x / m_size_piece.x);
				m_r1 = int(pos.y / m_size_piece.y);
				m_grid[m_r1][m_c1]->setSelectionMode();
				m_has_selection = true;
			}
			else {
				Vector2f pos = (Vector2f)Mouse::getPosition(*APP->getWindow()) - m_root_board;
				m_c2 = int(pos.x / m_size_piece.x);
				m_r2 = int(pos.y / m_size_piece.y);
				if (m_r1 == m_r2 && m_c1 == m_c2) {
					//todo cancel selection
					m_grid[m_r1][m_c1]->setCancelSelectionMode();
					m_has_selection = false;
				}
				else if (isNextTo(m_r2, m_c2)) {
					//todo swap two piece
					m_grid[m_r1][m_c1]->setCancelSelectionMode();
					m_grid[m_r2][m_c2]->setNormalMode();
					this->swapPiece(m_grid[m_r1][m_c1], m_grid[m_r2][m_c2]);
					m_has_selection = false;
					m_is_swapping = true;
				}
			}
		}
	}
	else {
		m_click_time = 0.f;
	}
}

void Match::moveAnimation(float delta_time)
{
	m_is_moving = false;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			// Move animation thực chất là setPosition cho các piece dựa vào X, Y của piece
			// cho đến khi nào khớp với Row và Column của piece thì xong
			float dx = m_grid[i][j]->getX() - (m_grid[i][j]->getC() + 0.5f) * m_size_piece.x;
			float dy = m_grid[i][j]->getY() - (m_grid[i][j]->getR() + 0.5f) * m_size_piece.y;

			if (dx != 0.f) {
				m_grid[i][j]->setX(m_grid[i][j]->getX() - 5.f * dx / abs(dx));
			}
			if (dy != 0.f) {
				// Game chuyển động chủ yếu là từ sự dịch chuyển của các ô từ trên xuống
				// Nên xử lý vận tốc nếu ăn theo hàng dọc, vận tốc rơi của ô sẽ x2
				if (m_grid[i][j]->getVelocity() == 0.f) {
					if (fabs(dy) / m_size_piece.y == 1.f)
						m_grid[i][j]->setVelocity(5.f);
					else
						m_grid[i][j]->setVelocity(10.f);
				}
				m_grid[i][j]->setY(m_grid[i][j]->getY() - m_grid[i][j]->getVelocity() * dy / fabs(dy));
			}

			if (dx != 0 || dy != 0)
				m_is_moving = true;
			else
				m_grid[i][j]->setVelocity(0.f);
		}
	}
}

void Match::findMatch(float delta_time)
{
	if (!m_is_moving) {
		int flag[8][8] = {};
		m_is_finished_turn = true;

		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (i < 7 && m_grid[i][j]->getType() == m_grid[i + 1][j]->getType()) {
					if (i > 0 && m_grid[i][j]->getType() == m_grid[i - 1][j]->getType()) {
						m_is_finished_turn = false;
						for (int k = -1; k <= 1; ++k) {
							m_grid[i + k][j]->setCanMatch(true);
							flag[i + k][j]++;
						}
					}
				}
				if (j < 7 && m_grid[i][j]->getType() == m_grid[i][j + 1]->getType()) {
					if (j > 0 && m_grid[i][j]->getType() == m_grid[i][j - 1]->getType()) {
						m_is_finished_turn = false;
						for (int k = -1; k <= 1; ++k) {
							m_grid[i][j + k]->setCanMatch(true);
							flag[i][j + k]++;
						}
					}
				}
			}
		}

		// Kiểm tra xem có được tiếp tục chơi không
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (flag[i][j] > 1) {
					m_is_continue_next_turn = true;
					return;
				}
			}
		}
	}
}

void Match::checkReverseSwap(float delta_time)
{
	if (m_is_swapping && !m_is_moving) {
		if (this->getScore() == 0) {
			this->swapPiece(m_grid[m_r1][m_c1], m_grid[m_r2][m_c2]);
			DATA->playSound("wrong");
			m_is_moving = true;
		}
		m_is_swapping = false;
	}
}

void Match::deleteAnimation(float delta_time)
{
	if (!m_is_moving) {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (m_grid[i][j]->canMatch()) {
					if (m_grid[i][j]->getAlpha() != 0) {
						// 15 / 255 => 17 turn delta_time
						m_grid[i][j]->setAlpha(m_grid[i][j]->getAlpha() - 15);
						m_is_moving = true;

						// Khi đã xóa xong, cập nhật điểm vào m_points
						if (m_grid[i][j]->getAlpha() == 0) {
							DATA->playSound("match");
							m_points[m_grid[i][j]->getType()] += m_grid[i][j]->getPoint();
						}
					}
				}
			}
		}
	}
}

void Match::updateBoard(float delta_time)
{
	if (!m_is_moving) {
		for (int i = 7; i >= 0; --i) {
			for (int j = 0; j < 8; ++j) {
				if (m_grid[i][j]->canMatch()) {
					for (int k = i - 1; k >= 0; --k) {
						if (!m_grid[k][j]->canMatch()) {
							this->swapPiece(m_grid[k][j], m_grid[i][j]);
							break;
						}
					}
				}
			}
		}

		for (int j = 0; j < 8; ++j) {
			for (int i = 7, k = 0; i >= 0; --i) {
				if (m_grid[i][j]->canMatch()) {
					m_grid[i][j]->resetPiece(randomPiece(i, j));
					m_grid[i][j]->setY(-m_size_piece.y * (k++ + 0.5f));
				}
			}
		}
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			m_grid[i][j]->updatePiece(delta_time);
		}
	}
}

/*-----------------------------------------------------------------------*/

void Match::searchAllOptions()
{
	int dr[4] = { 0, 1 }; // Right - Down
	int dc[4] = { 1, 0 }; // R - D

	for (int i = 7; i >= 0; --i) {
		for (int j = 7; j >= 0; --j) {
			for (int k = 0; k < 2; ++k) {
				int x = i + dr[k];
				int y = j + dc[k];
				if (x >= 0 && x < 8 && y >= 0 && y < 8) {
					this->swapPiece(m_grid[i][j], m_grid[x][y]);
					this->findMatch(0.f);
					int score = this->getScore();
					if (score > 0) {
						int priority = 7;
						for (int u = 0; u < 8; ++u) {
							for (int v = 0; v < 8; ++v) {
								if (m_grid[u][v]->canMatch()) {
									m_grid[u][v]->setCanMatch(false);
									if (m_grid[u][v]->getType() == 3 && priority > 1) priority = 1; // sword
									else if (m_grid[u][v]->getType() == 0 && priority > 2) priority = 2; // heart
									else if (m_grid[u][v]->getType() == 1 && priority > 3) priority = 3; // mana
									else if (m_grid[u][v]->getType() == 4 && priority > 4) priority = 4; // armor
									else if (m_grid[u][v]->getType() == 2 && priority > 5) priority = 5; // poison
									else priority = 6; // coin
								}
							}
						}
						m_option_list.push_back(Option(Vector2i(i, j), Vector2i(x, y), score, priority));
					}
					this->resetTurn(); // reset 'm_is_continue_next_turn' và 'm_is_finished_this_turn' do trong quá trình findMatch() tạo nên.
					this->swapPiece(m_grid[i][j], m_grid[x][y]);
				}
			}
		}
	}

	//sort(m_option_list.begin(), m_option_list.end(), cmp);
	for (int i = 0; i < (int)m_option_list.size(); ++i) {
		for (int j = i + 1; j < (int)m_option_list.size(); ++j) {
			if (m_option_list[i].m_score < m_option_list[j].m_score) {
				swap(m_option_list[i], m_option_list[j]);
			}
			else if (m_option_list[i].m_score == m_option_list[j].m_score) {
				if (m_option_list[i].m_priority > m_option_list[j].m_priority) {
					swap(m_option_list[i], m_option_list[j]);
				}
			}
		}
	}
}

void Match::botPlaying(float delta_time)
{
	if (m_is_bot_playing) {
		m_time_bot_play += delta_time;
		Vector2i pos_1 = m_option_list[0].m_pos_1;
		Vector2i pos_2 = m_option_list[0].m_pos_2;
		if (m_time_bot_play >= 1.5f) {
			m_grid[pos_1.x][pos_1.y]->setBotSelectionMode();
		}
		if (m_time_bot_play >= 2.f) {
			m_grid[pos_1.x][pos_1.y]->setCancelSelectionMode();
			this->swapPiece(m_grid[pos_1.x][pos_1.y], m_grid[pos_2.x][pos_2.y]);
			m_is_bot_playing = false;
			m_option_list.clear();
		}
	}
}

void Match::updateBot(float delta_time)
{
	if (!m_is_match_ready) {
		this->introMatch(delta_time);
	}
	if (m_time_bot_play == 0.f) {
		this->searchAllOptions();
		if (m_option_list.empty()) {
			// Nếu không có nước nào để ăn => reset toàn bộ piece
			this->initGridPiece();
			return;
		}
		m_is_bot_playing = true;
	}
	this->botPlaying(delta_time);
	this->moveAnimation(delta_time);
	this->findMatch(0.f);
	this->deleteAnimation(delta_time);
	this->updateBoard(delta_time);
}

/*-----------------------------------------------------------------------*/

void Match::initMatch()
{
	this->initBoard();
	this->initGridPiece();
}

void Match::updateMatch(float delta_time)
{
	if (!m_is_match_ready) {
		this->introMatch(delta_time);
		return;
	}
	this->checkView(delta_time);
	this->checkClick(delta_time);
	this->moveAnimation(delta_time);
	this->findMatch(delta_time);
	this->checkReverseSwap(delta_time);
	this->deleteAnimation(delta_time);
	this->updateBoard(delta_time);
}

void Match::renderMatch(RenderWindow* window)
{
	window->draw(*m_frame);
	window->draw(*m_board);
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			m_grid[i][j]->renderPiece(window);
		}
	}
}