#include "../histogram.h"
#include <cassert>

void
test_positive()
{
    double min=0;
    double max=0;
    find_minmax({1, 2, 3}, min, max);
    assert(min==1);
    assert(max==3);
}

void
test_one()
{
    double min=0;
    double max=0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min==-3);
    assert(max==-1);
}

void
test_two()
{
    double min=0;
    double max=0;
    find_minmax({2, 2, 2}, min, max);
    assert(min==2);
    assert(max==2);
}

void
test_three()
{
    double min=0;
    double max=0;
    find_minmax({1}, min, max);
    assert(min==1);
    assert(max==1);
}

int main()
{
   test_positive();
}
