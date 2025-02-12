#include <iostream>
#include "jpeg.hpp"
using namespace std;
#include <fstream>
#include "processing.hpp"

/* There are 4 or 5 arguments, including 
the executable name itself (i.e. argv[0]).*/
/*The desired width is greater than 0 and 
less than or equal to the original width 
of the input image.*/
/* The desired height is greater than 0 
and less than or equal to the original height 
of the input image.*/
int main(int argc, char *argv[]) {

if(argc!=4 && argc!=5){
  cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
  return 1;
}

Image image;

ifstream in_file(argv[1]);

if (!in_file) {
    cout << "Error: Could not open input file " << argv[1] << endl;
    return 1;
}

ofstream out_file(argv[2]);
if (!out_file) {
    cout << "Error: Could not open output file " << argv[2] << endl;
    return 1;
}
Image_init(&image, in_file);

int argv3 = stoi(argv[3]);
if(argv3 <= 0 || argv3 > Image_width(&image)){
  cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
  return 1;
}
int argv4 = Image_height(&image);
if(argc==5){
  argv4 = stoi(argv[4]);
  if(argv4 <= 0 || argv4 > Image_height(&image)){
    cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
  return 1;
  }

  seam_carve(&image, argv3, argv4);
}
else{
  seam_carve_width(&image, argv3);
}
Image_print(&image, out_file);
return 0;
}
//Check command line arguments (using argc and argv)
// Handle input and output (using fstreams)
// Apply the seam carve algorithm (using the processing and image interfaces)
