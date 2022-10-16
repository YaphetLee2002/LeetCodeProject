#include <iostream>
#include <random>
using namespace std;

int main()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(120, 200);
    for (int i = 1; i <= 500; ++i)
    {
        cout << u(e) << ",";
        if (! (i % 10)) cout << "    " <<endl;
    }
}