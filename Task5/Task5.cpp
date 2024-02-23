// Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1to20 ?

#include <iostream>
#include <vector>
#include <numeric>

void generatelist(std::vector<int>& list, int limit)
{
    std::vector<int> temp(limit);
    std::iota(temp.begin(), temp.end(), 1);
    //primary for loop accesses each element of vector
    for (int thing : temp)
    {
        //finds unique even divisors and removes them from vector
        for (int j = 1; j < limit; j++)
        {
            if (thing % j == 0)
            {
                temp.erase(std::remove(temp.begin(), temp.end(), j), temp.end());
            }
        }
    }
    list = temp;
}

int main()
{
    const int divisorLimit = 20;
    std::vector<int> list;
    //generatelist(list, divisorLimit);
    //for (int thing : list)
    //{
    //    std::cout << thing;
    //}
    bool found = false;
    unsigned long int numerator = 20;
    while (!found)
    {
        bool valid = true;
        //std::cout << numerator;
        //std::cout << "\n";
        //for loop goes through prime terms up to limit
        for (int i = 2; i <= divisorLimit; i++)
        {
            //std::cout << i;
            if (numerator % i == 0) 
            {
                //std::cout << i;
                //std::cout << " good\n";
                continue;
            }
            else
            {
                //std::cout << " bad\n";
                valid = false;
                break;
            }
        }
        if (numerator > 1000000000) { break; }
        if (valid == true)
        {
            std::cout << "\n";
            std::cout << numerator;
            found = true;
        }
        else
        {
            numerator+=20;
            continue;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
