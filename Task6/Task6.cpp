// Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <iostream>

int main()
{
	const int limit = 100;
	unsigned int unsquare = 0;
	unsigned int square = 0;
	for (int i = 1; i <= limit; i++)
	{
		unsquare += i;
		square += (i * i);
	}
	unsquare *= unsquare;
	std::cout << (square - unsquare);
}