#pragma once
#include "Button.h"
#include <iostream>
#include <vector>

class Menu : public sf::Drawable
{
	private:
		sf::RenderWindow* Window;
		std::vector<Button> Buttons{ 6, Button()};

		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	public:
		Menu(sf::RenderWindow&, const size_t&, const size_t&);
		// Constructor

		void ActivateHoverEffect();
		size_t getPressedButton();
		// Functions
};