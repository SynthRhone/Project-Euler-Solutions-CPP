//reattempting Task 1 with a different approach,
//use a vector to track each multiple being tested, add one each loop, when the element in the tracking vector hits it's limit add the current number to the total


#include <vector>
#include "Solutions.h"
using namespace std;

unsigned long solution1(const vector<int>& multiples, const int & limit)
{
    unsigned long counter = 0;
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

//depending on limit size, solution 2 can run from 2x-3x faster
unsigned long solution2(const vector<int>& multiples, const int & limit)
{
    unsigned long counter = 0;

    //create "loop vector"
    vector<int> looptrack(multiples.size(),1);
    
    for (int i = 1; i < limit; i++)
    {
        bool added = false;
        //iterate
        for (int j = 0; j < looptrack.size(); j++) 
        {
            if (looptrack.at(j) == multiples.at(j))
            {
                if (!added)
                {
                    counter += i;
                    added = true;
                }
                looptrack.at(j) = 1;
            }
            else
            {
                looptrack.at(j)++;
            }
        }
    }
    return counter;
}