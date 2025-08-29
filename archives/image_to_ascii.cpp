#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std; 
int main(int argc, char **argv) {
    if(argc < 2) {
        cout << "Please pass the PPM image as argument." << endl;
        return 1;
    } else {
        string density = "#N@%W$9876543210X&?ABC/()!;:^*+=~-_,.";
        ifstream image;
        image.open(argv[1]);
        string type = "", width = "", height = "", RGB = "";
        image >> type >> width >> height >> RGB; 
        int w = 0, h = 0;
        stringstream widthstream(width);
        widthstream >> w;
        stringstream heightstream(height); 
        heightstream >> h;
        if(w > 200 || h > 200) {
            cout << "Image to big (max supported size 200x200)" << std::endl;
            return 2;
        } else {
            string red = "", green = "", blue = "";
            int r = 0, g = 0, b = 0;
            int avg = 0, index = 0, newLine = 0;
            while(!image.eof()) {
                image >> red >> green >> blue;
                stringstream redstream(red);
                stringstream greenstream(green);
                stringstream bluestream(blue);
                redstream >> r;
                greenstream >> g;
                bluestream >> b;
                avg = (r + g + b) / 3;
                index = floor(avg / (255 / density.size()));
                if(index >= density.size()) {
                    index = density.size() - 1;
                }
                cout << density.at(index);
                index = 0;
                ++newLine;
                if(newLine == w) {
                    cout << endl;
                    newLine = 0;
                }
            }
        }
    }
    return 0;
}