/*
* Dylan Carlson
* Machine Learning
* Assignment 5
* 4/2018
*/

#include <iostream>
#include "mat.h"

using namespace std;

Matrix* center(Matrix, Matrix*); //Centers the Matrix


int main(int argc, char *argv[]){
  //////DECLARATIONS//////
  Matrix input_ppm; //input .ppm matrix
  Matrix center;

  //////INPUT////////
  input_ppm.readImagePpm(argv[1], "ppm"); //read in .ppm file to matrix


  //////CENTER MATRIX/////
  center = new Matrix(input_ppm); //creates a copy of input matrix to use for the centered matrix

  center(input_ppm, &center); //centers the 'center' matrix







}

void center(Matrix input, Matrix *center){
  Matrix mean;
  Matrix std;

  mean = input->meanVec();
  std = input->stddevVec();

  for(int r = 0; r < center->numRows(); r++){
    for(int c = 0; c < center->numCols(); c++){
      double zscore;
      zscore = ((input_ppm->get(r,c) - mean.get(0,c))/std.get(0,c));
      center->set(r,c, zscore);
    }
  }


}
