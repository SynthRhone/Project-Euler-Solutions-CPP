// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//programming solutions to project euler problems
//


#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int findSumMultiples(const vector<int>& multiples, int limit)
{
    int counter = 0;
    //i = current multiple under scrutiny
    for (int i = 1; i < limit; i++)
    {
        //this for loop is to access vector elements
        for (int j = 0; j < multiples.size(); j++)
        {
            //if a vector element is divisible by i, it's a multiple and can be added to the sum
            if (i % multiples.at(j) == 0)
            {
                counter += i;
                break;
            }
            else { continue; }
        }
    }
    return counter;
}

int main()
{
    vector<int> multiples = { 3,5 };
    auto timeStart = std::chrono::high_resolution_clock::now();
    int ans = findSumMultiples(multiples, 1000);
    auto timeEnd = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> timeExecution = timeEnd - timeStart;

    cout << ans << "\n" << timeExecution.count() << " execution time\n";
}
