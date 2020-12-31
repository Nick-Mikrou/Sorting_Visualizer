#include "Button.h"

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& fillColor, const size_t& id) noexcept
	:Rectangle(size), ID(id)
{
	Rectangle.setPosition(position);
	Rectangle.setFillColor(fillColor);
}	// Constructor

void Button::buttonConfiguration(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& fillColor, const sf::Color& textColor, const std::string& text, const size_t& id) noexcept
{
	Rectangle.setSize(size);
	Rectangle.setPosition(position);
	Rectangle.setFillColor(fillColor);

	if (!Font.loadFromFile("Fonts\\CONSOLA.ttf"))
		std::cerr << "Can not open font!" << std::endl;

	ButtonText.setFont(Font);
	ButtonText.setFillColor(textColor);
	ButtonText.setCharacterSize(18);
	ButtonText.setString(text);
	ButtonText.setPosition(getRectangle().getPosition().x + 15, getRectangle().getPosition().y + 3);

	setID(id);
}	// Configuration of button

void Button::setButtonPosition(const sf::Vector2f& position) noexcept
{
	Rectangle.setPosition(position);
}	// Set button position

void Button::setTextPosition() noexcept
{
	ButtonText.setPosition(getRectangle().getPosition().x, getRectangle().getPosition().y);
}	// Set text position

void Button::setFillColor(const sf::Color& color) noexcept
{
	Rectangle.setFillColor(color);
}	// Set button color

void Button::setHoverColor(const sf::Color& color) noexcept
{
	HoverColor = color;
}	// Set hover color

void Button::setTextColor(const sf::Color& color) noexcept
{
	ButtonText.setFillColor(color);
}	// Set text color

void Button::setID(const size_t& id) noexcept
{
	ID = id;
}	// Set ID

void Button::setIsPressed(const bool& pressed) noexcept
{
	isPressed = pressed;
}	// Set isPressed

size_t Button::getID() const noexcept
{
	return ID;
}	// Return ID 

bool Button::getIsPressed() const noexcept
{
	return isPressed;
}	// Return isPressed

sf::RectangleShape& Button::getRectangle() noexcept
{
	return Rectangle;
}	// Return Rectangle

sf::Text& Button::getButtonText() noexcept
{
	return ButtonText;
}	// Return button text

sf::Color Button::getHoverColor() const noexcept
{
	return HoverColor;
}	// Return hover color

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(Rectangle);
	target.draw(ButtonText);
}	// Draw button