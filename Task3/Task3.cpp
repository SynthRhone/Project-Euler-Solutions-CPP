// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>


bool prime(int numb)
{
    bool prime = true;
    for (int j = 2; j < numb; j++)
    {
        if (numb % j == 0)
        {
            prime = false;
            break;
        }
        else { continue; }
    }
    return prime;
}

int primefactor(long long int dividend)
{
    int out = 0;
    for (int i = 2; i < dividend; i++)
    {
        if (prime(i))
        {

            //std::cout << i <<"\n";
            if (dividend % i == 0)
            {
                std::cout << i<<"\n";
                dividend /= i;
                out = i;
            }
        }
        else { continue; }
    }
    if (dividend > out)
    {
        if (prime(dividend)) { out = dividend; }
    }
    return out;
}

int main()
{
    long long int stupidnumber = 600851475143;
    int ans = primefactor(stupidnumber);
    std::cout << ans << "\n";
}
