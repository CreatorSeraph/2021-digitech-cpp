#include <iostream>
#include "../../data-structure/cTimer.h"
#include "cLCG_Random.h"
#include "cRand_Random.h"
#include <ctime>

int main()
{
    using namespace std;

    cLCG_Random lcg_r(2);
    cRand_Random rand_r(time(nullptr));

    cout << lcg_r.rand() << endl;
    cout << rand_r.rand() << endl;

    time_t t = time(nullptr);
    struct tm* tm_now = localtime(&t);

    cout << tm_now->tm_hour << "½Ã " << tm_now->tm_min << "ºÐ " << tm_now->tm_sec << "ÃÊ" << endl;

    return 0;
}