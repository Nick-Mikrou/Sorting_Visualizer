#pragma once
#include "Button.h"

class Sorter
{
	private:
		std::vector<float> heights;
		Button BackButton;
		int Comparisons;
	
	public:
		void Init(sf::RenderWindow&, const size_t&)	noexcept;
		void Draw(sf::RenderWindow&, const size_t&, const size_t&) noexcept;
		void ActiveHoverColor(sf::RenderWindow&) noexcept;
		void HandleEvents(sf::RenderWindow&) noexcept;
		void ResetDataMembers() noexcept;
		void Delay(unsigned int&) noexcept;
		void Finish(sf::RenderWindow&) noexcept;

		size_t getPressedButton(sf::RenderWindow&) noexcept;
	
		void Swap(const size_t&, const size_t&) noexcept;
		
		void BubbleSort(sf::RenderWindow&, unsigned int&) noexcept;
		// Bubble Sort

		void MergeSort(sf::RenderWindow&, unsigned int&) noexcept;
		void Sort_M(sf::RenderWindow&, size_t, size_t, unsigned int&) noexcept;
		void Merge(sf::RenderWindow&, size_t, size_t, size_t, unsigned int&) noexcept;
		// Merge Sort

		void SelectionSort(sf::RenderWindow&, unsigned int&) noexcept;
		// Selection Sort

		void InsertionSort(sf::RenderWindow&, unsigned int&) noexcept;
		// Insertion Sort
};