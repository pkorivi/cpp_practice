#include "stdio.h"
//#include "conio.h"

void main() {
  printf("ggeeee\n" );
}

//Find pole in a list of elemnts. Pole divides elements such that everything to its left are smaller than pole and everything to right are larger than pole
// 2,3,5,3,2,1,6,7,10,7,9 here 6 is the pole
int solution(int A[], int N){
  int pole=0;
  int max_till_now=A[0];
  int pole_val = A[0];
  int pole_valid =1;
  int max_index =0;
  int i=0;
  for ( i = 0; i < N; i++) {
    if (A[i]>=max_till_now) {
      max_till_now = A[i];
      max_index = i;
    }

    if (A[i]>=pole_val && pole_valid==1) {
      //No problems
    }
    else if (pole_valid==0 && A[i]>=max_till_now) {
      pole_val = max_till_now;
      pole =max_index;
      pole_valid=1;
    }
    else if(A[i]<pole_val){
      pole_valid =0;
    }
    }

  if (pole_valid==0)
    return -1;

  return pole;
}

/*
//Answer this on stack overflow
https://stackoverflow.com/questions/15397637/interview-find-magnitude-pole-in-an-array?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
Stackoverflow format'
My solution

    int solution(int A[], int N){
       int pole=0;
       int max_till_now=A[0];
       //assume initial pole is first value
       int pole_val = A[0];
       int pole_valid =1;
       int max_index =0;
       int i=0;
       for ( i = 0; i < N; i++) {
          //This keeps the value of max till now, this would be needed if
          //the pole gets invalid and a new pole has to be chosen
          if (A[i]>=max_till_now) {
              max_till_now = A[i];
              max_index = i;
           }
          //if eleemnt parsed is greater than pole then its all well and good
          if (A[i]>=pole_val && pole_valid==1) {
              //No problems
          }
           //If pole is invalid and the current element parsed is greater than
           //or equal to current value parsed reassign pole
          else if (pole_valid==0 && A[i]>=max_till_now) {
              pole_val = max_till_now;
              pole =max_index;
              pole_valid=1;
          }
          //if the new parsed value is less than pole then pole gets invalid
          else if(A[i]<pole_val){
              pole_valid =0;
          }
        }

       if (pole_valid==0)
           return -1;

       return pole;
    }

*/
