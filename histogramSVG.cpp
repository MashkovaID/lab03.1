#include "histogramSVG.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg width='" << width << "' height='" << height << "' "
         << "viewBox='0 0 " << width << " " << height << "' "
         << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text) {
cout<<"<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";}

void
svg_rect(double x, double y, double width, double height, string stroke, string fill){
cout<<"<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"'/>";}

void show_histogram_svg(const vector<size_t>& bins)
{
        const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;

    string stroke = "red";
    string fill = "blue";
    const size_t MAX=IMAGE_WIDTH-TEXT_WIDTH;
    size_t max_lenght=0;
    for(size_t bin : bins)
    {
        if(bin>max_lenght)
        {
            max_lenght=bin*10;
        }
    }
    const bool scaling_needed=max_lenght>MAX;
    for(size_t bin:bins)
    {
        size_t height=bin;
        if(scaling_needed)
        {
            const double scaling_factor=(double)MAX/max_lenght;
            height=(size_t)(bin*scaling_factor);
        }

    const double bin_width = 10 * height;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, stroke, fill);
    top += BIN_HEIGHT;
}
    svg_end();
}
