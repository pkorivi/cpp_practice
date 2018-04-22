#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void check_prime(int n){
    if(n<=1){
        cout<<"Not prime"<<endl;
        return;
    }
    if(n<=3){
        cout<<"Prime"<<endl;
        return;
    }
          
    int k = sqrt(n);
    for(int i =2;i<=k;i++){
        if(n%i==0){
            cout<<"Not prime"<<endl;
            return;
        }
    }
    cout<<"Prime"<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int count, number;
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>number;
        check_prime(number);
    }
    return 0;
}

