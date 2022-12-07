#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <queue>
#include "day.hpp"
using namespace std;

class Day01 : public Day
{
public:
    string A() override
    {
        stringstream ss;
        ifstream infile("input/day01.txt");
        int highest = 0;
        int current = 0;
        string line;
        while (getline(infile, line))
        {
            current = line.empty() ? 0 : current + stoi(line);
            highest = max(highest, current);
        }
        ss << highest;
        return ss.str();
    }

    string B() override
    {
        stringstream ss;
        ifstream infile("input/day01.txt");
        priority_queue<int> max_heap;
        int current = 0;
        string line;
        while (getline(infile, line))
        {
            if (line.empty())
            {
                max_heap.push(current);
                current = 0;
            }
            else
            {
                current += stoi(line);
            }
        }
        
        int result = 0;
        for (int i=0; i<3; ++i)
        {
            result += max_heap.top();
            max_heap.pop();
        }
        ss << result;
        return ss.str();
    }
};



