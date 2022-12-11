#include <fstream>
#include <sstream>
#include <stack>
#include <array>
#include "day.hpp"
using namespace std;

/*
        [Q] [B]         [H]        
    [F] [W] [D] [Q]     [S]        
    [D] [C] [N] [S] [G] [F]        
    [R] [D] [L] [C] [N] [Q]     [R]
[V] [W] [L] [M] [P] [S] [M]     [M]
[J] [B] [F] [P] [B] [B] [P] [F] [F]
[B] [V] [G] [J] [N] [D] [B] [L] [V]
[D] [P] [R] [W] [H] [R] [Z] [W] [S]
 1   2   3   4   5   6   7   8   9 
*/

class Day05 : public Day
{
protected:
    vector<string> stacks_;
public:
    Day05()
    {
        stacks_.emplace_back("DBJV");
        stacks_.emplace_back("PVBWRDF");
        stacks_.emplace_back("RGFLDCWQ");
        stacks_.emplace_back("WJPMLNDB");
        stacks_.emplace_back("HNBPCSQ");
        stacks_.emplace_back("RDBSNG");
        stacks_.emplace_back("ZBPMQFSH");
        stacks_.emplace_back("WLF");
        stacks_.emplace_back("SVFMR");
    }

    string A() override
    {
        stringstream ss;
        ifstream infile("input/day05.txt");
        string line;
        while (getline(infile, line))
        {
            // move 1 from 4 to 1
            size_t from_pos = line.find_first_of("f");
            size_t to_pos = line.find_first_of("t");
            int quantity = stoi(line.substr(5,from_pos - 5));
            int from = stoi(line.substr(from_pos + 5, to_pos - from_pos - 5)) - 1;
            int to = stoi(line.substr(to_pos + 3)) - 1;

            for (int i = 0; i < quantity; ++i)
            {
                int item = stacks_[from].back();
                stacks_[from].pop_back();
                stacks_[to].push_back(item);
            }
        }

        for (const string& stack : stacks_)
            ss << stack.back();
        return ss.str();
    }

    string B() override
    {
        stringstream ss;
        ifstream infile("input/day05.txt");
        string line;
        while (getline(infile, line))
        {
        }
        return ss.str();
    }
};
