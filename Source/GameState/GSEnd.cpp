#include "GSEnd.h"

GSEnd::GSEnd()
{
    m_background = nullptr;
    m_frame = new RectangleShape();
    m_headline = new RectangleShape();
    m_title = new Text();

    m_id = new Text();
    m_name = new Text();
    m_level = new Text();
    m_change_level = new Text();
    m_coin = new Text();
    m_change_coin = new Text();

    m_button_home = new Button();
}

GSEnd::~GSEnd()
{
    if (m_background != nullptr) {
        delete m_background;
    }
    if (m_frame != nullptr) {
        delete m_frame;
    }
    if (m_headline != nullptr) {
        delete m_headline;
    }
    if (m_title != nullptr) {
        delete m_title;
    }
    if (m_name != nullptr) {
        delete m_name;
    }
    if (m_id != nullptr) {
        delete m_id;
    }
    if (m_level != nullptr) {
        delete m_level;
    }
    if (m_change_level != nullptr) {
        delete m_change_level;
    }
    if (m_coin != nullptr) {
        delete m_coin;
    }
    if (m_change_coin != nullptr) {
        delete m_change_coin;
    }
    if (m_button_home != nullptr) {
        delete m_button_home;
    }
}

GameState GSEnd::getTypeState()
{
    return GameState::END;
}

void GSEnd::initBoard()
{
    // frame
    m_frame->setSize(Vector2f(700.f, 640.f));
    m_frame->setTexture(DATA->getTexture("GUI/Frame/warning"));
    m_frame->setOrigin(m_frame->getSize() / 2.f);
    m_frame->setPosition(ScreenWidth / 2.f, ScreenHeight / 2.f - 10.f);
    
    // headline
    m_headline->setSize(Vector2f(600.f, 80.f));
    m_headline->setTexture(DATA->getTexture("GUI/Headline/level_complete"));
    m_headline->setOrigin(m_headline->getSize() / 2.f);
    m_headline->setPosition(m_frame->getPosition() + Vector2f(0.f, -m_frame->getSize().y / 2.f + 10.f));

    // title
    m_title->setFont(*DATA->getFont("LaoutBeautyPersonalUse"));
    if (DATA->isWinGame()) {
        m_title->setString("Win");
        m_title->setFillColor(Color(0, 255, 153));
    }
    else {
        m_title->setString("Lose");
        m_title->setFillColor(Color(255, 0, 102));
    }
    m_title->setCharacterSize(140);
    m_title->setOutlineThickness(1.5f);
    m_title->setOutlineColor(Color::Black);
    m_title->setOrigin(m_title->getGlobalBounds().width / 2.f, m_title->getGlobalBounds().height / 2.f);
    m_title->setPosition(m_headline->getPosition() + Vector2f(0.f, 130.f));
}

void GSEnd::initTextName()
{
    // id
    m_id->setFont(*DATA->getFont("TrulyMadlyDpad"));
    m_id->setString("ID: ");
    m_id->setCharacterSize(60);
    m_id->setFillColor(Color::Black);
    m_id->setOrigin(0.f, m_id->getGlobalBounds().height / 2.f);
    m_id->setPosition(m_frame->getPosition() + Vector2f(-200.f, -50.f));

    // name
    m_name->setFont(*DATA->getFont("TrulyMadlyDpad"));
    m_name->setString(USER->getName());
    m_name->setCharacterSize(60);
    m_name->setOutlineThickness(1.f);
    m_name->setOutlineColor(Color::Black);
    m_name->setFillColor(Color(230, 0, 115));
    m_name->setOrigin(0.f, m_id->getGlobalBounds().height / 2.f);
    m_name->setPosition(m_id->getPosition() + Vector2f(70.f, 0.f));
}

void GSEnd::initTextLevel()
{
    // level
    m_level->setFont(*DATA->getFont("TrulyMadlyDpad"));
    m_level->setString("Level: ");
    m_level->setCharacterSize(60);
    m_level->setFillColor(Color::Black);
    m_level->setOrigin(0.f, m_level->getGlobalBounds().height / 2.f);
    m_level->setPosition(m_id->getPosition() + Vector2f(0.f, 90.f));

    // change level
    m_change_level->setFont(*DATA->getFont("TrulyMadlyDpad"));
    if (DATA->isWinGame()) {
        if (USER->getLevel() == DATA->getMapLevel()) {
            m_change_level->setString("+1");
        }
        else {
            m_change_level->setString("0");
        }
        m_change_level->setFillColor(Color(0, 255, 153));
    }
    else {
        m_change_level->setString("0");
        m_change_level->setFillColor(Color(255, 0, 102));
    }

    m_change_level->setCharacterSize(60);
    m_change_level->setOutlineThickness(1.f);
    m_change_level->setOutlineColor(Color::Black);
    m_change_level->setOrigin(0.f, m_change_level->getGlobalBounds().height / 2.f);
    m_change_level->setPosition(m_level->getPosition() + Vector2f(160.f, 0.f));
}

void GSEnd::initTextCoin()
{
    // coin
    m_coin->setFont(*DATA->getFont("TrulyMadlyDpad"));
    m_coin->setString("Coin: ");
    m_coin->setCharacterSize(60);
    m_coin->setFillColor(Color::Black);
    m_coin->setOrigin(0.f, m_coin->getGlobalBounds().height / 2.f);
    m_coin->setPosition(m_level->getPosition() + Vector2f(0.f, 90.f));

    // change coin
    m_change_coin->setFont(*DATA->getFont("TrulyMadlyDpad"));
    if (DATA->isWinGame()) {
        m_change_coin->setString("+" + to_string(DATA->getCoinPlay()));
        m_change_coin->setFillColor(Color(0, 255, 153));
    }
    else {
        if (DATA->getCoinPlay() == 0)
            m_change_coin->setString("0");
        else
            m_change_coin->setString("-" + to_string(DATA->getCoinPlay()));

        m_change_coin->setFillColor(Color(255, 0, 102));
    }
    m_change_coin->setCharacterSize(60);
    m_change_coin->setOutlineThickness(1.f);
    m_change_coin->setOutlineColor(Color::Black);
    m_change_coin->setOrigin(0.f, m_change_coin->getGlobalBounds().height / 2.f);
    m_change_coin->setPosition(m_coin->getPosition() + Vector2f(140.f, 0.f));
}

void GSEnd::initButton()
{
    m_button_home->initButton(Vector2f(120.f, 120.f), "home");
    m_button_home->setPosition(m_frame->getPosition() + Vector2f(0.f, m_frame->getSize().y / 2.f));
    m_button_home->setFunction([]() {
        while (GAMESTATE->getCurrentState()->getTypeState() != GameState::SELECT_MAP) {
            GAMESTATE->popState();
        }
        });
}

void GSEnd::updateUser()
{
    if (DATA->isWinGame()) {
        if (USER->getLevel() == DATA->getMapLevel()) {
            USER->setLevel(USER->getLevel() + 1);
        }
        USER->setCoin(USER->getCoin() + DATA->getCoinPlay());
    }
    else {
        USER->setCoin(USER->getCoin() - DATA->getCoinPlay());
    }
}

void GSEnd::initState()
{
    m_background = DATA->getBackgroundGP();
    this->initBoard();
    this->initTextName();
    this->initTextLevel();
    this->initTextCoin();
    this->initButton();
    this->updateUser();
}

void GSEnd::updateState(float delta_time)
{
    m_button_home->updateButton(delta_time);
}

void GSEnd::renderState(RenderWindow* window)
{
    window->draw(*m_background);
    window->draw(*m_frame);
    window->draw(*m_headline);
    window->draw(*m_title);

    window->draw(*m_id);
    window->draw(*m_name);
    window->draw(*m_level);
    window->draw(*m_change_level);
    window->draw(*m_coin);
    window->draw(*m_change_coin);

    m_button_home->renderButton(window);
}