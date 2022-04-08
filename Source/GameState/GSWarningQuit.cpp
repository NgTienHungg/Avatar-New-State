#include "GSWarningQuit.h"

GSWarningQuit::GSWarningQuit()
{
	m_background = new Background();
	m_frame = new RectangleShape();
	m_headline = new RectangleShape();
	m_button_accept = new Button();
	m_button_cancel = new Button();
	m_message = new Text();
}

GSWarningQuit::~GSWarningQuit()
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
	if (m_button_accept != nullptr) {
		delete m_button_accept;
	}
	if (m_button_cancel != nullptr) {
		delete m_button_cancel;
	}
	if (m_message != nullptr) {
		delete m_message;
	}
}

GameState GSWarningQuit::getTypeState()
{
	return GameState::WARNING_QUIT;
}

void GSWarningQuit::initBoard()
{
	// frame
	m_frame->setSize(Vector2f(660.f, 500.f));
	m_frame->setTexture(DATA->getTexture("GUI/frame/warning"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(ScreenWidth / 2.f, ScreenHeight / 2.f);

	// headline
	m_headline->setSize(Vector2f(380.f, 90.f));
	m_headline->setTexture(DATA->getTexture("GUI/Headline/warning"));
	m_headline->setOrigin(m_headline->getSize() / 2.f);
	m_headline->setPosition(m_frame->getPosition() + Vector2f(0.f, -m_frame->getSize().y / 2.f));
}

void GSWarningQuit::initButton()
{
	// accept button
	m_button_accept->initButton(Vector2f(110.f, 110.f), "accept");
	m_button_accept->setPosition(m_frame->getPosition() + Vector2f(-130.f, m_frame->getSize().y / 2.f));
	m_button_accept->setFunction([]() { APP->getWindow()->close(); });

	// cancel button
	m_button_cancel->initButton(Vector2f(110.f, 110.f), "exit");
	m_button_cancel->setPosition(m_frame->getPosition() + Vector2f(130.f, m_frame->getSize().y / 2.f));
	m_button_cancel->setFunction([]() { GAMESTATE->popState(); });
}

void GSWarningQuit::initMessage()
{
	m_message->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_message->setString("	Quit game\nAre you sure?");
	m_message->setCharacterSize(65);
	m_message->setFillColor(Color(255, 0, 102));
	m_message->setOutlineThickness(1.f);
	m_message->setOutlineColor(Color::Black);
	m_message->setOrigin(m_message->getGlobalBounds().width / 2.f, m_message->getGlobalBounds().height / 2.f);
	m_message->setPosition(m_frame->getPosition() + Vector2f(0.f, -20.f));
}

void GSWarningQuit::initState()
{
	m_background->initBackground();
	this->initBoard();
	this->initButton();
	this->initMessage();
}

void GSWarningQuit::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	m_button_accept->updateButton(delta_time);
	m_button_cancel->updateButton(delta_time);
}

void GSWarningQuit::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_frame);
	window->draw(*m_headline);

	window->draw(*m_button_accept);
	window->draw(*m_button_cancel);
	window->draw(*m_message);
}