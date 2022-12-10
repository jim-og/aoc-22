#include <fstream>
#include <sstream>
#include <unordered_set>
#include <array>
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
        int group_size = 3;
        int count = 0;
        int total = 0;
        array<int, 52> letters;
        letters.fill(0);

        while (getline(infile, line))
        {
            unordered_set<char> unique_letters;
            for (int i=0; i < line.size(); ++i)
            {
                char letter = line[i];
                if (unique_letters.count(letter) > 0)
                    continue;
                
                unique_letters.insert(letter);
                int index = letter - 'a';
                if (index < 0)
                    index = letter - 'A' + 26;
                letters.at(index)++;

                if (letters.at(index) == group_size)
                {
                    total += (index + 1);
                    letters.fill(0);
                    break;
                }
            }
        }
        ss << total;
        return ss.str();
    }
};
