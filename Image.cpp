#include <cassert>
#include "Image.hpp"

// REQUIRES: img points to an Image
//           0 < width && 0 < height
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height, with
//           all pixels initialized to RGB values of 0.
void Image_init(Image* img, int width, int height) {
  img->height = height;
  img->width = width;
  

  Matrix *b = &img->blue_channel;
  Matrix_init(b,width,height);

  Matrix *g = &img->green_channel;
  Matrix_init(g,width,height);

  Matrix *r = &img->red_channel;
  Matrix_init(r,width,height);
  
}
 

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img, is
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
void Image_init(Image* img, std::istream& is) {
    
    
  char ppm;
  is >> ppm;
  int num;
  is >> num;
  int width;
  int height;
  is >> width >> height;
  img->height = height;
  img->width = width;

  is >> num;

  int r; 
  int g; 
  int b;

  Matrix_init(&img->red_channel, width, height);
  Matrix_init(&img->green_channel, width, height);
  Matrix_init(&img->blue_channel, width, height);
 
  for(int i = 0; i < img->height; i++){
    for(int j = 0;j < img->width; j++){

      is >> r >> g >> b;

      Matrix *red = &img->red_channel;
      *Matrix_at(red, i, j) = r;

      Matrix *green = &img->green_channel;
      *Matrix_at(green, i, j) = g;

      Matrix *blue = &img->blue_channel;
      *Matrix_at(blue, i, j) = b;
    }
  }
}


// REQUIRES: img points to a valid Image
// MODIFIES: os
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.

void Image_print(const Image* img, std::ostream& os) {
  os << "P3" << "\n";
  os << img->width << " " << img->height << "\n";
  os << "255" << "\n";

  const Matrix *r = &img->red_channel;
  const Matrix *g = &img->green_channel;
  const Matrix *b = &img->blue_channel;

  for(int i = 0; i < img->height; i++){
    for(int j = 0;j < img->width; j++){
      os << *Matrix_at(r,i,j) << " ";
      os << *Matrix_at(g,i,j) << " ";
      os << *Matrix_at(b,i,j) << " ";
    }
    
    //newline at the end
    os << "\n";

  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
  return img->width; // TODO Replace with your implementation!
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
  return img->height; // TODO Replace with your implementation!
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
  Pixel pixel;
  const Matrix *red = &img->red_channel;
  
  const Matrix *green = &img->green_channel;

  const Matrix *blue = &img->blue_channel;
      
  pixel.r = *Matrix_at(red,row,column);
  pixel.g = *Matrix_at(green,row,column); 
  pixel.b = *Matrix_at(blue,row,column);

  return pixel;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
  Matrix *red = &img->red_channel;
  *Matrix_at(red, row, column) = color.r;

  Matrix *green = &img->green_channel;
  *Matrix_at(green, row, column) = color.g;

  Matrix *blue = &img->blue_channel;
  *Matrix_at(blue, row, column) = color.b;
}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
  Matrix *red = &img->red_channel;
  Matrix *green = &img->green_channel;
  Matrix *blue = &img->blue_channel;
  for(int i = 0; i < img->height; i++){
    for(int j = 0;j < img->width; j++){
    *Matrix_at(red, i, j) = color.r;
    *Matrix_at(green, i, j) = color.g;
    *Matrix_at(blue, i, j) = color.b; //since data is a 1 dimensional vector
    }
  }
}
