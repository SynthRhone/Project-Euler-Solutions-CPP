// Task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Task 4 - Find the largest palindrome made from the product of two 3-digit numbers

#include <iostream>
#include <string>
#include <vector>

//checks if number is palindrome
bool numberispalindrome(int num)
{
    std::string numstring = std::to_string(num);
    int numlength = numstring.length();
    int halflen = std::floor(float(numlength)/float(2));
    std::string lasthalf = numstring.substr(halflen, halflen);
    std::string firsthalf = numstring.substr(0, halflen);
    //std::cout << firsthalf + lasthalf+"\n";
    std::reverse(lasthalf.begin(), lasthalf.end());
    if (firsthalf.compare(lasthalf) == 0)
    {
        //std::cout << firsthalf + " " + lasthalf + "\n";
        return true; 
    }
    else { return false; }
}

int main()
{
    const int looplimit = 900;
    bool endloop = false;
    //std::cout << "Hello World!\n";
    //double for loop, going from 999, to loop limit, should hit the largest result faster
    for (int i = 999; i > looplimit; i--)
    {
        for (int j = 999; j > looplimit; j--)
        {
            if (numberispalindrome(i*j))
            {
                char message[100];
                sprintf_s(message, "palindrome found: %d * %d = %d\n", i, j, i * j);
                std::cout << message;
                endloop = true;
                break;
            }
            if (endloop == true) { break; }
        }
        if (endloop == true) { break; }
    }
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu