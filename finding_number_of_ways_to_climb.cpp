#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
/*If  a stair case can be climbed in 1,2,3 steps at a time. find number of possible combinations to climb n stairs. 
This is similar to fibonacci with 3 values. Same should be repeating if there were 4 values given then next is sum of previous 4*/
using namespace std;

/*Recursion Fibonacci*/
int find_perm(int stairs){
    if(stairs<1)
        return 0;
    else if(stairs==1)
        return 1;
    else if(stairs ==2 )
        return 2;
    else if(stairs ==3)
        return 4;
    
    return find_perm(stairs-1) + find_perm(stairs-2) +find_perm(stairs-3);
}
/*Linear approach - nth is sum of n-1,n-2,n-3*/
int find_perm2(int stairs){
     if(stairs<1)
        return 0;
    else if(stairs==1)
        return 1;
    else if(stairs ==2 )
        return 2;
    else if(stairs ==3)
        return 4;
    
    vector <int> a = {1,2,4};
    int k;
    for(int n =4; n<=stairs; n++){
        k = (n-1)%3;
        a[k] = a[0]+a[1]+a[2];
    }
    return a[k];
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int cases,stairs;
    cin>>cases;
    for(int i=0;i<cases;i++){
        cin>>stairs;
        cout<<find_perm2(stairs)<<endl;
    }
    return 0;
}

