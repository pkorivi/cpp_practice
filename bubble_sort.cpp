/*This is a efficient implementation over basic one*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    int num_swaps=0;
    bool is_sorted = false;
    int last_bub = n-1;
    while(!is_sorted){
        is_sorted = true; //assumption
        for(int i =0; i<last_bub; i++){
            if(a[i]>a[i+1]){
                num_swaps++;
                is_sorted = false;//if we are performing a swap then array is not sorted
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        last_bub--;//last element is sorted after one pass, thus in next loop check for one element less
    }
    cout<<"Array is sorted in "<<num_swaps<<" swaps."<<endl;
    cout<<"First Element: "<<a.front()<<endl;
    cout<<"Last Element: "<<a.back()<<endl;
  return 0;
}


///////////////////////////////////////////////////
/*Basic implementation*/
for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < n - 1; j++) {
        // Swap adjacent elements if they are in decreasing order
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
        }
    }
    
}
