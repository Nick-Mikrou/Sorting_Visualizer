#include "Sorter.h"
#include <thread>

void Sorter::Init(sf::RenderWindow& window, const size_t& numrectangles) noexcept
{
	BackButton.buttonConfiguration(sf::Vector2f(70, 30), sf::Vector2f(10, 10), sf::Color(168, 168, 168), sf::Color::White, "Back", 1);
	BackButton.setHoverColor(sf::Color(255, 165, 0));

	srand((unsigned int)time(NULL));

	for (size_t i = 0; i < numrectangles; ++i)
		heights.push_back(static_cast<float>(rand() % 300));
}

void Sorter::Draw(sf::RenderWindow& window, const size_t& first, const size_t& second) noexcept
{
	window.clear();
	BackButton.draw(window, sf::RenderStates::Default);

	sf::RectangleShape rect;

	for (size_t i = 0; i < heights.size(); ++i)
	{
		rect.setSize(sf::Vector2f(window.getSize().x / heights.size(), heights.at(i)));
		rect.setFillColor(sf::Color::White);
		rect.setOutlineThickness(1.0f);
		rect.setOutlineColor(sf::Color::Black);
		rect.setPosition(i * rect.getSize().x, 600 - heights.at(i));

		if (i == first)
			rect.setFillColor(sf::Color::Red);

		if (i == second)
			rect.setFillColor(sf::Color::Red);

		window.draw(rect);
	}
	window.display();
}

void Sorter::ActiveHoverColor(sf::RenderWindow& window) noexcept
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	if (BackButton.getRectangle().getGlobalBounds().contains(mousePositionFloat))
		BackButton.setFillColor(BackButton.getHoverColor());
	else
		BackButton.setFillColor(sf::Color(168, 168, 168));
}

void Sorter::HandleEvents(sf::RenderWindow& window) noexcept
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::MouseMoved)
			ActiveHoverColor(window);

		if (e.type == e.MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
		{
			size_t res = getPressedButton(window);

			if (res == 1)
			{
				BackButton.setIsPressed(true);
			}
		}
	}
}

void Sorter::ResetDataMembers() noexcept
{
	BackButton.setIsPressed(false);
	heights.clear();
	Comparisons = 0;
}

void Sorter::Delay(unsigned int& ms) noexcept
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void Sorter::Finish(sf::RenderWindow& window) noexcept
{
	while (!BackButton.getIsPressed())
	{
		HandleEvents(window);

		window.clear();

		BackButton.draw(window, sf::RenderStates::Default);
		sf::RectangleShape rect;
		for (int i = 0; i < heights.size(); ++i)
		{
			rect.setSize(sf::Vector2f(window.getSize().x / heights.size(), heights.at(i)));
			rect.setFillColor(sf::Color::Green);
			rect.setOutlineThickness(1.0f);
			rect.setOutlineColor(sf::Color::Black);
			rect.setPosition(i * rect.getSize().x, 600 - heights.at(i));

			window.draw(rect);
		}
		window.display();
	}

	std::cout << "Comparisons : " << Comparisons << std::endl;
}

size_t Sorter::getPressedButton(sf::RenderWindow& window) noexcept
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	if (BackButton.getRectangle().getGlobalBounds().contains(mousePositionFloat))
		return BackButton.getID();

	return -1;
}

void Sorter::Swap(const size_t& first, const size_t& second) noexcept
{
	int temp = heights.at(first);
	heights.at(first) = heights.at(second);
	heights.at(second) = temp;
}

void Sorter::BubbleSort(sf::RenderWindow& window, unsigned int& delay) noexcept
{

	for (size_t i = 0; i < heights.size() - 1; ++i)
	{
		for (size_t j = 0; j < heights.size() - i - 1; ++j)
		{
			HandleEvents(window);

			if (BackButton.getIsPressed()) break;

			++Comparisons;
			if (heights.at(j) > heights.at(j + 1))
			{
				Swap(j, j + 1);	
				Draw(window, j, j + 1);
				Delay(delay);
			}			
		}
	}

	Finish(window);

	ResetDataMembers();
}	// Bubble Sort

void Sorter::MergeSort(sf::RenderWindow& window, unsigned int& delay) noexcept
{
	Sort_M(window, 0, heights.size() - 1, delay);

	Finish(window);

	ResetDataMembers();
}	// Merge Sort

void Sorter::Sort_M(sf::RenderWindow& window, size_t left, size_t right, unsigned int& delay) noexcept
{
	
	if (left < right)
	{
		HandleEvents(window);

		if (BackButton.getIsPressed()) return;

		size_t mid = (left + right) / 2;

		Sort_M(window, left, mid, delay);
		Sort_M(window, mid + 1, right, delay);
		Merge(window, left, mid, right, delay); 
	}
}

void Sorter::Merge(sf::RenderWindow& window, size_t left, size_t mid, size_t right, unsigned int& delay) noexcept
{
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;	

	std::vector<float> Left, Right;

	for (size_t i = 0; i < n1; ++i)
		Left.push_back(heights.at(left + i));
	for (size_t j = 0; j < n2; ++j)
		Right.push_back(heights.at(mid + 1 + j));

	size_t i = 0;
	size_t j = 0;
	size_t k = left;

	while (i < n1 && j < n2)
	{
		HandleEvents(window);

		if (BackButton.getIsPressed()) break;

		++Comparisons;
		if (Left.at(i) <= Right.at(j))
		{
			heights.at(k) = Left.at(i);
			++i;
			
		}
		else
		{
			heights.at(k) = Right.at(j);
			++j;
		
		}
		Draw(window, k,-1);
		Delay(delay);
		++k;
	}
	
	while (i < n1)
	{
		HandleEvents(window);

		if (BackButton.getIsPressed()) break;

		heights.at(k) = Left.at(i);
		++i;
		++k;	
	}

	while (j < n2)
	{
		HandleEvents(window);

		if (BackButton.getIsPressed()) break;

		heights.at(k) = Right.at(j);
		++j;
		++k;
	}
}

void Sorter::SelectionSort(sf::RenderWindow& window, unsigned int& delay) noexcept
{
	for (size_t i = 0; i < heights.size(); ++i)
	{
		size_t min = i;
		for (size_t j = i + 1; j < heights.size(); ++j)
		{
			HandleEvents(window);

			if (BackButton.getIsPressed()) break;

			++Comparisons;
			if (heights.at(j) < heights.at(min))
				min = j;

			Draw(window, i, j);
			Delay(delay);
		}
		Swap(i, min);
		Draw(window, i, min);
		Delay(delay);

		if (BackButton.getIsPressed()) break;
	}

	Finish(window);

	ResetDataMembers();
}	// Selection Sort

void Sorter::InsertionSort(sf::RenderWindow& window, unsigned int& delay) noexcept
{
	size_t j;
	for (size_t i = 1; i < heights.size(); ++i)
	{
		float key = heights.at(i);
		j = i - 1;

		while (j >= 0 && heights.at(j) > key)
		{
			HandleEvents(window);

			if (BackButton.getIsPressed()) break;

			++Comparisons;
			heights.at(j + 1) = heights.at(j);		
			
			Draw(window, i, j);
			Delay(delay);

			--j;
		}
		heights.at(j + 1) = key;
	}

	Finish(window);

	ResetDataMembers();
}	// Insertion Sort