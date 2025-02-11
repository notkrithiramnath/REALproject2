#include "Matrix.hpp"
#include "Matrix_test_helpers.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  const int value = 30;
  Matrix_init(&mat, width, height);
  Matrix_fill(&mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(&mat, r, c), value);
    }
  }
}
TEST(test_Matrix_width){

  Matrix mat;
  const int width = 5;
  const int height = 5;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_width(&mat), width);
}

TEST(test_Matrix_height){

  Matrix mat;
  const int width = 5;
  const int height = 5;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_height(&mat), height);
}
TEST(test_Matrix_height_onerow){

  Matrix mat;
  const int width = 5;
  const int height = 1;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_height(&mat), height);
}
TEST(test_Matrix_width_onecol){

  Matrix mat;
  const int width = 1;
  const int height = 5;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_width(&mat), width);
}

TEST(test_print_grid) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  const int value = 30;
  Matrix_init(&mat, width, height);
  Matrix_fill(&mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(&mat, r, c), value);
    }
  }
}

TEST(test_Matrix_fill_border) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  const int value = 30;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      //check if a border value
      if(r == 0 || r == height - 1 || c == 0 || c == width - 1){
        ASSERT_EQUAL(*Matrix_at(&mat, r, c), value);
      }
    }
  }
}

TEST(test_Matrix_max_basic) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  const int value = 30;
  Matrix_init(&mat, width, height);//everything is 0
  *Matrix_at(&mat, 0, 0) = value;//dereference and modify 1 number at 0,0 to be value
  *Matrix_at(&mat, 4, 4) = value;
  ASSERT_EQUAL(Matrix_max(&mat), value);
  ASSERT_EQUAL(Matrix_max(&mat), value);
}
TEST(test_Matrix_max_negative) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  
  Matrix_init(&mat, width, height);//everything is 0
  Matrix_fill(&mat, -5);//fill the matrix with negative value
  *Matrix_at(&mat, 4, 4) = -1;
  ASSERT_EQUAL(Matrix_max(&mat), -1);
  
}
TEST(test_Matrix_max_same) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  
  Matrix_init(&mat, width, height);//everything is 0
  Matrix_fill(&mat, 6);
 
  ASSERT_EQUAL(Matrix_max(&mat), 6);
  
}
TEST(test_Matrix_max_onerow){
  Matrix mat;
  const int width = 5;
  const int height = 1;
  const int value = 30;
  Matrix_init(&mat, width, height);//everything is 0
  *Matrix_at(&mat, 0, 0) = value;//dereference and modify 1 number at 0,0 to be value
  *Matrix_at(&mat, 0, 4) = value;
  ASSERT_EQUAL(Matrix_max(&mat), value);
}
TEST(test_Matrix_column_of_min_value_in_row) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  const int value = 30;
  //fill the matrix with the value
  Matrix_init(&mat, width, height);
  Matrix_fill(&mat, value);
  *Matrix_at(&mat, 0, 0) = 0;//set the first element to 0
  //iterate through each row and check if the column of the min value is 0
  for(int r = 0; r < height; ++r){
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(&mat, r, 0, width), 0);
  }
}
TEST(test_Matrix_min_value_in_row) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  const int value = 30;
  //fill the matrix with the value
  Matrix_init(&mat, width, height);
  Matrix_fill(&mat, value);
  *Matrix_at(&mat, 0, 0) = 0;//set the first element to 0
  
  
  ASSERT_EQUAL(Matrix_min_value_in_row(&mat, 0, 0, width), 0);//check if the min value is 0 in the first row
  
}
TEST_MAIN() // Do NOT put a semicolon here
