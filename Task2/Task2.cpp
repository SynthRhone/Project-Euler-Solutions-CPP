// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>

int fibonacci(const std::vector<int> &divisors, int limit)
{
    int out = 0;
    int fib_a = 1;
    int fib_b = 0;
    bool flip = false;
    
    //1,1,2,3,5,8,13,21
    while (fib_a + fib_b < limit) 
    {
        if (flip)
        {
            fib_a += fib_b;
            flip = !flip;
            for (int i : divisors) 
            {
                if (fib_a % i == 0) { out += fib_a; }
            }
        }
        else
        {
            fib_b += fib_a;
            flip = !flip;
            //std::cout << fib_b << "\n";
            for (int i : divisors)
            {
                if (fib_b % i == 0) { out += fib_b; }
            }
        }
    }
    return out;
}


int main()
{
    std::vector<int> divisors = { 2 };
    int limit = 4000000;
    auto timeStart = std::chrono::high_resolution_clock::now();
    int ans = fibonacci(divisors, limit);
    auto timeEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeExecution = timeEnd - timeStart;

    std::cout << ans << "\n" << timeExecution.count() << " execution time\n";
}
