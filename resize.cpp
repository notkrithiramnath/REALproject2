#include <iostream>
#include "jpeg.hpp"
using namespace std;
#include <fstream>


// There are 4 or 5 arguments, including the executable name itself (i.e. argv[0]).
// The desired width is greater than 0 and less than or equal to the original width of the input image.
// The desired height is greater than 0 and less than or equal to the original height of the input image.
int main(int argc, char *argv[]) {
bool no_error = true;
Image *image;
std::ifstream in_file(argv[0]);
if (!in_file.is_open()) {
    cout << "Error: Could not open input file " << *argv[0] << endl;
    return 1;
}

std::ifstream out_file(argv[1]);
if (!out_file.is_open()) {
    cout << "Error: Could not open input file " << *argv[1] << endl;
    return 1;
}

Image_init(image, in_file);
if(argc!=4||argc!=5){
  no_error = false;
}
int argv2 = *argv[2]-0;
if(argv2 < 0 || argv2 > Image_width(image)){
  no_error = false;
}
int argv3 = *argv[3]-0;
if(argv3 < 0 || argv3 > Image_width(image)){
  no_error = false;
}
  
if(no_error==false){
  cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
  return 1;
}
return 0;
}
//Check command line arguments (using argc and argv)
// Handle input and output (using fstreams)
// Apply the seam carve algorithm (using the processing and image interfaces)
