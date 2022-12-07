#include "src/day01.hpp"
#include "src/day02.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "No day specified" << endl;
        return 1;
    }

    int today =  stoi(argv[1]);   
    cout << "Day: " << today << endl;
    switch (today)
    {
        case 1: { Day01().Run(); break; }
        case 2: { Day02().Run(); break; }
        default:
        {
            cout << "Day not solved, yet" << endl;
        }
    }
    return 0;
}