#include "StateManager.h"

StateManager::StateManager(Character* character)
{
	m_character = character;
	m_current_state = nullptr;

	m_idle_state = new IdleState(m_character);
	m_run_state = new RunState(m_character);
	m_weak_attack_state = new WeakAttackState(m_character);
	m_normal_attack_state = new NormalAttackState(m_character);
	m_strong_attack_state = new StrongAttackState(m_character);
	m_ultimate_attack_state = new UltimateAttackState(m_character);
	m_defend_state = new DefendState(m_character);
	m_hurt_state = new HurtState(m_character);
	m_death_state = new DeathState(m_character);
}

StateManager::~StateManager()
{
	if (m_current_state != nullptr) {
		delete m_current_state;
	}
	if (m_idle_state != nullptr) {
		delete m_idle_state;
	}
	if (m_run_state != nullptr) {
		delete m_run_state;
	}
	if (m_weak_attack_state != nullptr) {
		delete m_weak_attack_state;
	}
	if (m_normal_attack_state != nullptr) {
		delete m_normal_attack_state;
	}
	if (m_strong_attack_state != nullptr) {
		delete m_strong_attack_state;
	}
	if (m_ultimate_attack_state != nullptr) {
		delete m_ultimate_attack_state;
	}
	if (m_defend_state != nullptr) {
		delete m_defend_state;
	}
	if (m_hurt_state != nullptr) {
		delete m_hurt_state;
	}
	if (m_death_state != nullptr) {
		delete m_death_state;
	}
}

Vector2f StateManager::getScale()
{
	return m_scale;
}

void StateManager::changeState(CharacterState type)
{
	switch (type)
	{
	case CharacterState::IDLE:
		m_current_state = m_idle_state;
		break;
	case CharacterState::RUN:
		m_current_state = m_run_state;
		break;
	case CharacterState::ATK_WEAK:
		m_current_state = m_weak_attack_state;
		break;
	case CharacterState::ATK_NORMAL:
		m_current_state = m_normal_attack_state;
		break;
	case CharacterState::ATK_STRONG:
		m_current_state = m_strong_attack_state;
		break;
	case CharacterState::ATK_ULTIMATE:
		m_current_state = m_ultimate_attack_state;
		break;
	case CharacterState::DEFEND:
		m_current_state = m_defend_state;
		break;
	case CharacterState::HURT:
		m_current_state = m_hurt_state;
		break;
	case CharacterState::DEATH:
		m_current_state = m_death_state;
		break;
	default:
		break;
	}
}

IState* StateManager::getCurrentState()
{
	return m_current_state;
}

void StateManager::initStateManager(Vector2f scale)
{
	m_scale = scale;

	int f_x, f_y, f_count;
	string file_name = m_character->getName();
	ifstream fin; fin.open("Data/FileData/" + file_name + ".txt");

	//todo Đọc ghi file để lấy spriteSheet, frameCount cho mỗi animation
	fin >> f_x >> f_y >> f_count;
	m_idle_state->initState(Vector2i(f_x, f_y), f_count);
	fin >> f_x >> f_y >> f_count;
	m_run_state->initState(Vector2i(f_x, f_y), f_count);
	fin >> f_x >> f_y >> f_count;
	m_weak_attack_state->initState(Vector2i(f_x, f_y), f_count);
	fin >> f_x >> f_y >> f_count;
	m_normal_attack_state->initState(Vector2i(f_x, f_y), f_count);
	fin >> f_x >> f_y >> f_count;
	m_strong_attack_state->initState(Vector2i(f_x, f_y), f_count);
	fin >> f_x >> f_y >> f_count;
	m_ultimate_attack_state->initState(Vector2i(f_x, f_y), f_count);
	fin >> f_x >> f_y >> f_count;
	m_defend_state->initState(Vector2i(f_x, f_y), f_count);
	fin >> f_x >> f_y >> f_count;
	m_hurt_state->initState(Vector2i(f_x, f_y), f_count);
	fin >> f_x >> f_y >> f_count;
	m_death_state->initState(Vector2i(f_x, f_y), f_count);
	fin.close();

	changeState(CharacterState::RUN);
}

void StateManager::updateStateManager(float delta_time)
{
	m_current_state->updateState(delta_time);
}

void StateManager::renderStateManager(RenderWindow* window)
{
	m_current_state->renderState(window);
}