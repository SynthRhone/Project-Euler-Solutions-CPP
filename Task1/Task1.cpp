// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//programming solutions to project euler problems

#include <iostream>
#include <vector>
#include <chrono>

#include "Solutions.h"
using namespace std;

int main()
{
    vector<int> multiples = { 3,5 };
    auto timeStart = std::chrono::high_resolution_clock::now();
    unsigned long ans = solution2(multiples, 5000000);
    auto timeEnd = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> timeExecution = timeEnd - timeStart;

    cout << ans << "\n" << timeExecution.count() << "ms execution time\n";
}
