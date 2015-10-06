// Daily 213 Hard CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file("input.txt");
	do
	{
		const unsigned int charCount = 10000;
		bool* boolStr = new bool[charCount];
		for (unsigned int i = 0; i < charCount; ++i)
		{
			boolStr[i] = (file.get() == 'a');
		}

		const bool* const arrayEnd = boolStr + charCount;
		unsigned int results[4] = {}; //results[0] is max discrepancy, then start, end, and step

		for (unsigned int step = 1; charCount / step > results[0]; ++step)
		{
			for (const bool* start = boolStr; start < arrayEnd; start += 1)
			{
				int discrepancy = 0;
				const bool* end = start;
				do
				{
					end += step;
					discrepancy += *end ? 1 : -1;  //add the next value
					if (abs(discrepancy) > results[0])
					{
						results[0] = abs(discrepancy);
						results[1] = start - boolStr;
						results[2] = end - boolStr;
						results[3] = step;
					}
				} while (end < arrayEnd);
			}
		}

		std::cout << results[0] << "\t[" << results[1] << ":" << results[2] << ":" << results[3] << "]\n";

	} while (!file.eof());

	std::cin.ignore();
	return 0;
}
