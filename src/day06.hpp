#include <fstream>
#include <sstream>
#include <unordered_map>
#include <queue>
#include "day.hpp"
using namespace std;

class Day06 : public Day
{
protected:
    int FindMarker(int marker_size)
    {
        ifstream infile("input/day06.txt");
        string line;
        while (getline(infile, line))
        {
            unordered_map<char, int> unique;
            queue<char> queue;
            int count = 1;
            int marker_length = marker_size;

            for (char letter : line)
            {
                unique[letter]++;
                queue.emplace(letter);

                if (queue.size() > marker_length)
                {
                    char remove = queue.front();
                    queue.pop();
                    if (--unique[remove] == 0)
                        unique.erase(remove);
                }

                if (unique.size() == marker_length)
                    return count;

                ++count;
            }
        }
        return -1;
    }

public:
    string A() override
    {
        stringstream ss;
        ss << FindMarker(4);
        return ss.str();
    }

    string B() override
    {
        stringstream ss;
        ss << FindMarker(14);
        return ss.str();
    }
};
