#include "Matrix.hpp"
#include "Image_test_helpers.hpp"
#include "unit_test_framework.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(image_init){
  Image img;
  Image_init(&img, 2, 2);
  ASSERT_EQUAL(Image_width(&img), 2);
  ASSERT_EQUAL(Image_height(&img), 2);


}
TEST(test_print) {
  Image img;
  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(&img, 2, 2);
  Image_set_pixel(&img, 0, 0, red);
  Image_set_pixel(&img, 0, 1, green);
  Image_set_pixel(&img, 1, 0, blue);
  Image_set_pixel(&img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(&img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n"; //red and green
  correct << "0 0 255 255 255 255 \n"; //blue and white
  ASSERT_EQUAL(s.str(), correct.str());
}

TEST(test_Image_width) {
  Image img;
  Image_init(&img, 2, 2);
  // Check that the width is 2
  ASSERT_EQUAL(Image_width(&img), 2);

}
TEST(test_image_fill){
  Image img;
  Pixel color = {0, 0, 1};//random color
  Image_init(&img, 3, 3);
  Image_fill(&img, color);
  // Check that the pixel at (0, 0) is black
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).r, color.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).g, color.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).b, color.b);

  //check that pixel at (2,2) is the color
  ASSERT_EQUAL(Image_get_pixel(&img, 2, 2).r, color.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 2, 2).g, color.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 2, 2).b, color.b);

//larger test
  Pixel color = {200, 150, 78};//random color
  Image_init(&img, 20, 30);
  Image_fill(&img, color);

  // Check that the pixel at (0, 0) is color
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).r, color.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).g, color.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).b, color.b);

  //check that pixel at the middle is the color
  ASSERT_EQUAL(Image_get_pixel(&img, 5, 10).r, color.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 10, 5).g, color.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 15, 19).b, color.b);

  //check that pixel at the end is the color
  ASSERT_EQUAL(Image_get_pixel(&img, 19, 29).r, color.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 19, 29).g, color.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 19, 29).b, color.b);



}

TEST(test_Image_height) {
  Image img;
  Image_init(&img, 2, 2);
  // Check that the height is 2
  ASSERT_EQUAL(Image_height(&img), 2);
}
TEST(test_image_init2){
  Image img;
  //P3, height/width/ max rgb value/pixels
  istringstream is("P3\n2 2\n255\n255 0 0 0 0 0 \n255 255 255 255 255 255 \n");
  string correct = "P3\n2 2\n255\n255 0 0 0 0 0 \n255 255 255 255 255 255 \n";

  Image_init(&img, is);
  ostringstream os;
  Image_print(&img, os);
  ASSERT_EQUAL(os.str(), correct);
  


}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.hpp as needed.

TEST_MAIN() // Do NOT put a semicolon here
