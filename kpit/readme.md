The folder contains code to solve the challenge to rotate sub matrices.

Assumptions::
  * Data is read from an input file, default file is data_in.txt is provided
  * Data contains only integers with space separation
  * First line states number of rows and columns and sub matrix size followed by space separated data_in
      4 4 2 // a 4x4 matrix sub divided into 3x3
      1 2 3 4 //4x4 matrix with space separated integers
      4 5 6 5
      7 8 9 6
      4 5 6 5
  * Data in the input file is as mentioned on the top

Compilation::
g++ -std=c++14 kpit.cpp -o th

Execution:
./th - Default file with main input is executed
./th "input_file_name" example: ./th ./th data_2.txt 

Limitations::
  * Only rotates square matrices
  * Code can be implemented in reverse order such that swaps are replaced by assignments improving computational efficiency
