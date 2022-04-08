#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "GameConfig.h"
#include "Singleton.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>

#define DATA DataManager::getInstance()

using namespace std;
using namespace sf;

class DataManager : public Singleton<DataManager>
{
private:
	map<string, Texture*> m_map_texture;
	map<string, Font*> m_map_font;
	map<string, Sound*> m_map_sound;
	map<string, Music*> m_map_music;

	string m_texture_path;
	string m_font_path;
	string m_sound_path;

	bool m_is_allow_sound;
	bool m_is_allow_music;

	Sprite* m_bg_gp; // Background gameplay
	int m_map_level;
	int m_coin_play;
	bool m_is_win;

public:
	DataManager();
	~DataManager();

	void addTexture(string name);
	void removeTexture(string name);
	Texture* getTexture(string name);

	void addFont(string name);
	void removeFont(string name);
	Font* getFont(string name);

	void addSound(string name);
	void removeSound(string name);
	Sound* getSound(string name);

	void addMusic(string name);
	void removeMusic(string name);
	Music* getMusic(string name);

	void playSound(string name);
	void playMusic(string name);
	void pauseMusic(string name);
	void stopMusic(string name);
	void updateMusic();

	bool isAllowSound();
	void setAllowSound(bool allow);

	bool isAllowMusic();
	void setAllowMusic(bool allow);

	vector<pair<string, pair<int, int>>> readRecordFile();
	void writeRecordFile(vector<pair<string, pair<int, int>>> users);

	/*-------------------------------------------*/

	void setMapLevel(int level);
	int getMapLevel();

	void setBackgroundGP(Sprite* background);
	Sprite* getBackgroundGP();

	void setResultGame(bool is_win);
	bool isWinGame();

	void setCoinPlay(int coin_play);
	int getCoinPlay();
};