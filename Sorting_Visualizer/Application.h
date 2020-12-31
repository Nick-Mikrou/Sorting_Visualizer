#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Sorter.h"

class Application
{
	private:	
		sf::RenderWindow Window;
		unsigned int width, height;
		std::string title;

		Menu menu;
		Sorter sorter;

	public:
		Application(const std::string&, const unsigned int&, const unsigned int&) noexcept;
		// Constructor

		void Run() noexcept;
		// Render
};