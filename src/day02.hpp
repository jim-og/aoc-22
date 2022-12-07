#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <queue>
#include "day.hpp"
using namespace std;

class Day02 : public Day
{
private:

    enum Result {
        WIN = 6,
        DRAW = 3,
        LOSS = 0,
    };
    enum Hand {
        ROCK = 1,
        PAPER = 2,
        SCISSORS = 3,
    };
    
    static bool A_IsDraw(char opp, char you)
    {
        return opp == (you - ('X' - 'A'));
    }

    static int A_Hand (char input)
    {
        return input == 'X' ? ROCK 
            : input == 'Y' ? PAPER 
            : input == 'Z' ? SCISSORS 
            : 0;
    }

    static int A_Match (char opp, char you)
    {
        if (A_IsDraw(opp,you))
            return DRAW;
        if (opp == 'A') // rock
        {
            return you == 'Y' ? WIN : LOSS;
        }
        else if (opp == 'B') // paper
        {
            return you == 'X' ? LOSS : WIN;
        }
        else // scissors
        {
            return you == 'X' ? WIN : LOSS;
        }
    }

    static int B_Hand (char input)
    {
        return input == 'A' ? ROCK 
            : input == 'B' ? PAPER 
            : input == 'C' ? SCISSORS 
            : 0;
    }

    static int B_Match(char opp_hand, char result)
    {
        if (result == 'Y')
        {
            return B_Hand(opp_hand);
        }
        else if (result == 'X')
        {
            if (opp_hand == 'A')
                return B_Hand('C');
            else if (opp_hand == 'B')
                return B_Hand('A');
            else
                return B_Hand('B');
        }
        else
        {
            if (opp_hand == 'A')
                return B_Hand('B');
            else if (opp_hand == 'B')
                return B_Hand('C');
            else
                return B_Hand('A');
        }
    }

    static int B_Result (char result)
    {
        return result == 'X' ? LOSS 
            : result == 'Y' ? DRAW 
            : WIN;
    }

public:

    string A() override
    {
        /*
        Opponent                You     Points
            A       rock        X       1
            B       paper       Y       2
            C       scissors    Z       3

        Win     6
        Draw    3
        */
        stringstream ss;
        ifstream infile("input/day02.txt");
        string line;
        int total = 0;
        while (getline(infile, line))
        {
            char opp = line[0];
            char you = line[2];
            total += A_Hand(you) + A_Match(opp, you);
        }
        ss << total;
        return ss.str();        
    }

    string B() override
    {
        stringstream ss;
        ifstream infile("input/day02.txt");
        string line;
        int total = 0;
        while (getline(infile, line))
        {
            char opp = line[0];
            char result = line[2];
            int score = 0;
            score += B_Result(result);
            score += B_Match(opp, result);
            total += score;
        }
        ss << total;
        return ss.str(); 
    }
};



