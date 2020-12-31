#include "Menu.h"

Menu::Menu(sf::RenderWindow& window, const size_t& height, const size_t& weight)
{
	Window = &window;

	Buttons.at(0).buttonConfiguration(sf::Vector2f(140, 30), sf::Vector2f(10, 10), sf::Color(168, 168, 168), sf::Color::White, "Bubble Sort", 1);
	Buttons.at(0).setHoverColor(sf::Color(255, 165, 0));

	Buttons.at(1).buttonConfiguration(sf::Vector2f(140, 30), sf::Vector2f(160, 10), sf::Color(168, 168, 168), sf::Color::White, "Merge Sort", 2);
	Buttons.at(1).setHoverColor(sf::Color(255, 165, 0));

	Buttons.at(2).buttonConfiguration(sf::Vector2f(170, 30), sf::Vector2f(310, 10), sf::Color(168, 168, 168), sf::Color::White, "Selection Sort", 3);
	Buttons.at(2).setHoverColor(sf::Color(255, 165, 0));

	Buttons.at(3).buttonConfiguration(sf::Vector2f(170, 30), sf::Vector2f(490, 10), sf::Color(168, 168, 168), sf::Color::White, "Insertion Sort", 4);
	Buttons.at(3).setHoverColor(sf::Color(255, 165, 0));

	Buttons.at(5).buttonConfiguration(sf::Vector2f(70, 30), sf::Vector2f(700, 550), sf::Color(168, 168, 168), sf::Color::White, "Exit", 5);
	Buttons.at(5).setHoverColor(sf::Color(255, 165, 0));
}	// Constructor

size_t Menu::getPressedButton()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*Window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	for (auto& button : Buttons)
	{
		if (button.getRectangle().getGlobalBounds().contains(mousePositionFloat))
			return button.getID();
	}

	return -1;
}	// Return button which pressed

void Menu::ActivateHoverEffect()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*Window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	for (auto& button : Menu::Buttons)
	{
		if (button.getRectangle().getGlobalBounds().contains(mousePositionFloat))
			button.setFillColor(button.getHoverColor());
		else
			button.setFillColor(sf::Color(168, 168, 168));
	}
}	// Activate Hover Effect

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& button : Buttons)
		target.draw(button);
}	// Draw Menu