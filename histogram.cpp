#include"histogram.h"
#include<vector>
#include<iostream>

using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    min=numbers[0];
    max=numbers[0];
    if(numbers.size()>0)
    {
    for(double number : numbers)
     {
        if(number<min)
            {min=number;}
        if(number>max)
            {max=number;}
     }
    }
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count)
{
    double min, max;
     find_minmax(numbers, min, max);
    vector<size_t> bins(bin_count);
    for(double number : numbers)
    {
        size_t bin=(size_t)((number-min)/(max-min)*bin_count);
        if(bin==bin_count)
            {bin--;}
    bins[bin]++;
    }
    return bins;
}

void show_histogram_text(const vector<size_t>& bins)
{
    const size_t MAX=80-4;
    size_t max_count=0;
    for(size_t bin : bins)
    {
        if(bin>max_count)
            {max_count=bin;}
    }
    const bool scaling_needed=max_count>MAX;

    for (size_t bin : bins)
    {
        if(bin<100) {cout<<" ";}
        if(bin<10) {cout<<"  ";}
        cout<<bin<<"|";

    size_t height = bin;
    if(scaling_needed)
    {
        const double scaling_factor=(double)MAX/max_count;
        height=(size_t)(bin*scaling_factor);
    }

    for(size_t i=0; i<height; i++)
        {cout<<"*";}
    cout<<"\n";
    }
}
