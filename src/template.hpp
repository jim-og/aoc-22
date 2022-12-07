#include <fstream>
#include <sstream>
#include "day.hpp"
using namespace std;

class DayX : public Day
{
public:
    string A() override
    {
        stringstream ss;
        ifstream infile("input/dayX.txt");
        string line;
        while (getline(infile, line))
        {  
        }
        return ss.str();
    }

    string B() override
    {
        stringstream ss;
        ifstream infile("input/dayX.txt");
        string line;
        while (getline(infile, line))
        {
        }
        return ss.str();
    }
};
