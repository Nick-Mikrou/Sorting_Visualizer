#include "Application.h"

unsigned int DELAY = 50;
static const size_t NUMBER_OF_RECTANGLES = 20;

Application::Application(const std::string& title, const unsigned int& width, const unsigned int& height) noexcept
	:Window(sf::VideoMode{width,height}, title, sf::Style::Titlebar), width(width), height(height), menu(Window, width, height)
{
	Window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - Window.getSize().x / 2
								   ,sf::VideoMode::getDesktopMode().height/ 2 - Window.getSize().y / 2));
}	// Constructor

void Application::Run() noexcept
{
	while (Window.isOpen())
	{
		sf::Event e;
		while (Window.pollEvent(e))
		{
			if (e.type == sf::Event::MouseMoved)
				menu.ActivateHoverEffect();

			if (e.type == sf::Event::Closed)
				Window.close();

			if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
			{	
				size_t res = menu.getPressedButton();

				if (res == 1)
				{
					sorter.Init(Window, NUMBER_OF_RECTANGLES);
					sorter.BubbleSort(Window, DELAY);
				}
				else if (res == 2)
				{
					sorter.Init(Window, NUMBER_OF_RECTANGLES);
					sorter.MergeSort(Window, DELAY);
				}
				else if (res == 3)
				{
					sorter.Init(Window, NUMBER_OF_RECTANGLES);
					sorter.SelectionSort(Window, DELAY);
				}
				else if (res == 4)
				{
					sorter.Init(Window, NUMBER_OF_RECTANGLES);
					sorter.InsertionSort(Window, DELAY);
				}
				else if (res == 5)
				{
					Window.close();
				}				
			}			
		}
		Window.clear();
		Window.draw(menu);
		Window.display();
	}
}	// Application Loop