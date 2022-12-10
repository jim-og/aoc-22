#include <fstream>
#include <sstream>
#include <unordered_set>
#include "day.hpp"
using namespace std;

class Day03 : public Day
{
public:
    string A() override
    {
        stringstream ss;
        ifstream infile("input/day03.txt");
        string line;
        int total = 0;
        while (getline(infile, line))
        {
            unordered_set<char> items;
            for (int i=0; i < line.size()/2; ++i)
                items.insert(line[i]);

            for (int i=line.size()/2; i < line.size(); ++i)
            {
                char letter = line[i];
                if (items.count(letter) > 0)
                {
                    items.erase(letter);
                    int priority = letter - 'a' + 1;
                    if (priority < 0)
                        priority = letter - 'A' + 27;
                    total += priority;
                }
            }
        }
        ss << total;
        return ss.str();
    }

    string B() override
    {
        stringstream ss;
        ifstream infile("input/day03.txt");
        string line;
        while (getline(infile, line))
        {
        }
        return ss.str();
    }
};
