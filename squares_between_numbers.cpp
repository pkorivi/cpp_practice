#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a;
        cin>>b;
        int count =0;
        int c = ceil(sqrt(a));
        int d = floor(sqrt(b));
        cout<<(d-c)+1<<endl;
        
    }
    return 0;
}

