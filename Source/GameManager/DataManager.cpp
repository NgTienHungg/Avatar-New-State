#include "DataManager.h"
#include "../GameState/GSBase.h"

DataManager::DataManager()
{
	string path = "Data/";
	m_texture_path = path + "Texture/";
	m_font_path = path + "Font/";
	m_sound_path = path + "Sound/";
	m_is_allow_sound = true;
	m_is_allow_music = true;

	m_bg_gp = nullptr;
	m_map_level = 1;
	m_coin_play = 0;
	m_is_win = true;
}

DataManager::~DataManager()
{
	for (auto it : m_map_texture) {
		if (it.second != nullptr) {
			delete it.second;
		}
	}
	m_map_texture.clear();

	for (auto it : m_map_font) {
		if (it.second != nullptr) {
			delete it.second;
		}
	}
	m_map_font.clear();

	for (auto it : m_map_sound) {
		if (it.second != nullptr) {
			delete it.second;
		}
	}
	m_map_sound.clear();

	for (auto it : m_map_music) {
		if (it.second != nullptr) {
			delete it.second;
		}
	}
	m_map_music.clear();

	if (m_bg_gp != nullptr) {
		delete m_bg_gp;
	}
}

void DataManager::addTexture(string name)
{
	Texture* texture = new Texture();
	texture->loadFromFile(m_texture_path + name + ".png");

	auto it = m_map_texture.find(name);
	if (it != m_map_texture.end()) {
		return;
	}
	m_map_texture[name] = texture;
}

void DataManager::removeTexture(string name)
{
	auto it = m_map_texture.find(name);
	if (it == m_map_texture.end()) {
		return;
	}
	if (it->second != nullptr) {
		delete it->second;
	}
	m_map_texture.erase(it);
}

Texture* DataManager::getTexture(string name)
{
	auto it = m_map_texture.find(name);
	if (it != m_map_texture.end()) {
		return it->second;
		it->second = nullptr;
	}
	this->addTexture(name);
	return this->getTexture(name);
}

void DataManager::addFont(string name)
{
	Font* font = new Font();
	font->loadFromFile(m_font_path + name + ".TTF");

	auto it = m_map_font.find(name);
	if (it != m_map_font.end()) {
		return;
	}
	m_map_font[name] = font;
}

void DataManager::removeFont(string name)
{
	auto it = m_map_font.find(name);
	if (it == m_map_font.end()) {
		return;
	}
	if (it->second != nullptr) {
		delete it->second;
	}
	m_map_font.erase(it);
}

Font* DataManager::getFont(string name)
{
	auto it = m_map_font.find(name);
	if (it != m_map_font.end()) {
		return it->second;
	}
	this->addFont(name);
	return this->getFont(name);
}

void DataManager::addSound(string name)
{
	Sound* sound = new Sound();
	SoundBuffer* buffer = new SoundBuffer();
	buffer->loadFromFile(m_sound_path + name + ".wav");
	sound->setBuffer(*buffer);

	auto it = m_map_sound.find(name);
	if (it != m_map_sound.end()) {
		return;
	}
	m_map_sound[name] = sound;
}

void DataManager::removeSound(string name)
{
	auto it = m_map_sound.find(name);
	if (it == m_map_sound.end()) {
		return;
	}
	if (it->second != nullptr) {
		delete it->second;
	}
	m_map_sound.erase(it);
}

Sound* DataManager::getSound(string name)
{
	auto it = m_map_sound.find(name);
	if (it != m_map_sound.end()) {
		return it->second;
	}
	this->addSound(name);
	return this->getSound(name);
}

void DataManager::addMusic(string name)
{
	Music* music = new Music();
	music->openFromFile(m_sound_path + name + ".wav");

	auto it = m_map_music.find(name);
	if (it != m_map_music.end()) {
		return;
	}
	m_map_music[name] = music;
}

void DataManager::removeMusic(string name)
{
	auto it = m_map_music.find(name);
	if (it == m_map_music.end()) {
		return;
	}
	if (it->second != nullptr) {
		delete it->second;
	}
	m_map_music.erase(it);
}

Music* DataManager::getMusic(string name)
{
	auto it = m_map_music.find(name);
	if (it != m_map_music.end()) {
		return it->second;
	}
	this->addMusic(name);
	return this->getMusic(name);
}

void DataManager::playSound(string name)
{
	if (m_is_allow_sound) {
		DATA->getSound(name)->play();
	}
}

void DataManager::playMusic(string name)
{
	if (m_is_allow_music) {
		Music* music = this->getMusic(name);
		if (music->getStatus() == Music::Stopped || music->getStatus() == Music::Paused) {
			music->setVolume(50);
			music->setLoop(true);
			music->play();
		}
	}
}

void DataManager::pauseMusic(string name)
{
	auto it = m_map_music.find(name);
	if (it != m_map_music.end()) {
		it->second->pause();
	}
}

void DataManager::stopMusic(string name)
{
	auto it = m_map_music.find(name);
	if (it != m_map_music.end()) {
		it->second->stop();
	}
}

void DataManager::updateMusic()
{
	// pause music
	if (!m_is_allow_music) {
		for (auto it : m_map_music) {
			if (it.second->getStatus() == Music::Playing) {
				it.second->pause();
				return;
			}
		}
	}

	// turn on music in game play
	GameState state = GAMESTATE->getCurrentState()->getTypeState();
	if (state == GameState::PLAY || state == GameState::PAUSE || state == GameState::WARNING_HOME) {
		if (m_is_allow_music && this->getMusic("gameplay")->getStatus() == Music::Paused) {
			this->playMusic("gameplay");
		}
	}

	// turn on background music
	if (state != GameState::INTRO && state != GameState::PLAY && state != GameState::PAUSE && state != GameState::WARNING_HOME) {
		if (m_is_allow_music && (this->getMusic("background")->getStatus() == Music::Paused
			|| this->getMusic("background")->getStatus() == Music::Stopped))
		{
			this->playMusic("background");
		}
	}
}

bool DataManager::isAllowSound()
{
	return m_is_allow_sound;
}

void DataManager::setAllowSound(bool allow)
{
	m_is_allow_sound = allow;
}

bool DataManager::isAllowMusic()
{
	return m_is_allow_music;
}

void DataManager::setAllowMusic(bool allow)
{
	m_is_allow_music = allow;
}

vector<pair<string, pair<int, int>>> DataManager::readRecordFile()
{
	string s;
	vector<string> v;
	ifstream fin("Data/FileData/hi_score.txt");
	while (getline(fin, s)) {
		v.push_back(s);
	}
	fin.close();

	vector<pair<string, pair<int, int>>> users;
	for (int i = 0; i < (int)v.size(); i += 3) {
		string name = v[i];
		int level = stoi(v[i + 1]);
		int coin = stoi(v[i + 2]);
		users.push_back({ name, {level, coin} });
	}
	return users;
}

void DataManager::writeRecordFile(vector<pair<string, pair<int, int>>> users)
{
	ofstream fout("Data/FileData/hi_score.txt");
	for (int i = 0; i < (int)users.size(); ++i) {
		string name = users[i].first;
		int level = users[i].second.first;
		int coin = users[i].second.second;
		fout << name << endl << level << endl << coin;
		if (i != users.size() - 1) fout << endl;
	}
	fout.close();
}

void DataManager::setBackgroundGP(Sprite* background)
{
	m_bg_gp = background;
}

Sprite* DataManager::getBackgroundGP()
{
	return m_bg_gp;
}

void DataManager::setMapLevel(int level)
{
	m_map_level = level;
}

int DataManager::getMapLevel()
{
	return m_map_level;
}

void DataManager::setResultGame(bool is_win)
{
	m_is_win = is_win;
}

bool DataManager::isWinGame()
{
	return m_is_win;
}

void DataManager::setCoinPlay(int coin_play)
{
	m_coin_play = coin_play;
}

int DataManager::getCoinPlay()
{
	return m_coin_play;
}