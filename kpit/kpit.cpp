
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
read through readme.md
*/

/**
** function to split the given string with multiple space seperated integers
** @param : string to split, seperator used for splitting
**/
vector<int> split( string str, string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
     vector<int> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(stoi(current));
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

/**
** function to swap two elements - swap by reference
** @param : two elemnts to be swapped
**/
void swap(int& a, int& b){
  int temp=0;
  temp = a;
  a = b;
  b = temp;
}

/**
** This is a recursive function, it Shifts the outer layer of the matrix then calls itself with inner matrix
** reduction happens in this format 5x5 -> 3x3 -> 1x1; 4x4->2x2->0x0;
** @param : source matrix, sub_marix start_row, sub  start_column, size of matrix
**/
void shift_matrix(int **src,int r_start, int c_start, int size, int value ){
  //check boundary conditions
  if(size==0)
    return;
  else if( size==1){
    //if only last 1x1 is left, fill the value
    src[r_start][c_start]=value;
    return;
  }
  //Initial values determining where the sub matrix ends - comments are described considering a 3x3 matrix
  int r_end = r_start + size;
  int c_end = c_start + size;
  int i = r_start, j = c_start;
  int temp_value = value;
  //shift from top row 1st to last column (0-2)
  for ( ; j < c_end; j++) {
    swap(src[i][j],temp_value); //swap the temp value with the current value
  }
  j--;//reduce the column value which was incremented in for loop
  i++; //shift to next row
  //fill till the end of the column - now right most column is shifted
  for( ; i < r_end; i++) {
    swap(src[i][j],temp_value);
  }
  i--;//reduce the value which was incremented in for loop
  j--; //shift to last but one column
  //shift the last row
  for( ; j >= c_start;j--){
    swap(src[i][j],temp_value);
  }
  j++;//increase the value which was decremented in for loop
  i--; //jump to the middle row
  //fill the values till last but one in the first column
  for( ; i > r_start; i--) {
    swap(src[i][j],temp_value);
  }
  //function call for shifting of the inner sub matrix
  shift_matrix(src,r_start+1, c_start+1,size-2,temp_value);
}

/**
** Function to rotate the sub matrix in clockwise direction
** @param : source matrix,  sub_matrix  start_row, sub_marix start coumn, size of matrix to be rotated
**/
void rotate_sub_matrix(int **src, int r_start, int c_start, int mat_size){
  if(mat_size<=1)
    return;
  //extract the first value - i.e., ast value to occue in clock wise rotation.
  int first_val = 0;
  int first_val_index = (int)(mat_size/2);
  //If the matrix is odd(3*3) - it will be the center value, if its even then its left shfited by 1 coulumn in the halfth column.
  first_val = (mat_size%2==0) ? src[r_start+first_val_index][c_start+first_val_index-1] : src[r_start+first_val_index][c_start+first_val_index];
  //Call function to shift the matrix
  shift_matrix(src, r_start, c_start,mat_size,first_val);
}
/**
** Main function to run the code
**/

int main(int argc, char const *argv[]){
  //Initialize a file reader
  ifstream infile;

  //Read data from passed input file else read from default file
  if(argc == 2){
    infile.open(argv[1]);
  }
  else{
    infile.open("data_in.txt");
  }

  //check if the file can be opened
  if(!infile.is_open()){
    std::cout << " File could not be read" << '\n';
    return 0;
  }
  //Initialize string to read from file
  string line;
  //Read first line - read number of rows and columns
  getline(infile, line);
  //split lines with space seperation and return an ineteger - print the read values
  vector<int> v = split(line, " ");
  std::cout <<" rows: "<< v[0]<<" columns: " <<v[1]<< " sub_matrix: "<<v[2] << '\n';
  //check if the whole matrix can be sub divided accordingly
  if (v[0]% v[2] != 0 || v[1]% v[2] != 0) {
    std::cout << " Sub matrix does not divide the matrix properly -- Exiting" << '\n';
    return 0;
  }

  //Create a pointer that holds memory to matrix and store the matrix by extracting it from file
  int **src;
  src = new int*[v[0]];
  for (size_t i = 0; i < v[0]; i++) {
    getline(infile, line);
    vector<int> v1 = split(line, " ");
    src[i] = new int[v[1]];
    for (size_t j = 0; j < v[1]; j++) {
      src[i][j]=  v1[j];
    }
  }

  //Extract sub matrix and rotate it
  for (size_t i = 0; i < v[0]; i += v[2]) {
    for (size_t j = 0; j < v[1]; j += v[2]) {
      rotate_sub_matrix(src, i, j, v[2]);
    }
  }

  //Print the rotated Matrix - Final Answer
  for (size_t i = 0; i < v[0]; i++) {
    for (size_t j = 0; j < v[1]; j++) {
      std::cout << src[i][j] <<" ";
    }
    std::cout << '\n';
  }
  return 0;
}
