#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public sf::Drawable
{
	private:
		sf::RectangleShape Rectangle;
		sf::Text ButtonText;
		sf::Color HoverColor;
		sf::Font Font;

		size_t ID;
		bool isPressed = false;

	public:
		Button() = default;
		Button(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& fillColor, const size_t& id) noexcept;	
		// Constructors

		void buttonConfiguration(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& fillColor, const sf::Color& textColor, const std::string& text, const size_t& id) noexcept; 
		// Configuration of the button

		void setButtonPosition(const sf::Vector2f&) noexcept;		
		void setTextPosition()						noexcept;								
		void setFillColor(const sf::Color& color)	noexcept;
		void setHoverColor(const sf::Color&)		noexcept;
		void setTextColor(const sf::Color&)			noexcept;
		void setID(const size_t&)					noexcept;
		void setIsPressed(const bool&)				noexcept;
		
		size_t getID()						  const noexcept;
		bool getIsPressed()					  const noexcept;
		sf::RectangleShape& getRectangle()			noexcept;
		sf::Text& getButtonText()					noexcept;
		sf::Color getHoverColor()			  const noexcept;

		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};