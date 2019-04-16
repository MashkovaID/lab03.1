#include<iostream>
#include<vector>
#include "histogram.h"
#include "histogramSVG.h"

using namespace std;


vector<double> input_numbers(size_t number_count)
{
    vector<double> result(number_count);
    for (size_t i=0; i<number_count; i++)
    {cin>>result[i];}
    return result;
}


vector<size_t> make_histogram(vector<double> numbers, size_t bin_count)
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



int main()
{
    size_t number_count;
    cerr<<" Enter number count\n";
    cin>>number_count;

    cerr<<" Enter numbers\n";
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr<<" Enter bin count\n";
    cin>>bin_count;

    const auto bins=make_histogram(numbers, bin_count);

    show_histogram_svg(bins);


}
