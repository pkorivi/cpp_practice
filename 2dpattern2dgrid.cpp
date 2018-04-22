#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string find_match(vector< vector<int> > src, vector< vector<int> > mat){
    int R,C,r,c,match;
    for( R=0;R<(src.size() - mat.size()+1);R++){ //search area
        for( C=0;C<(src[R].size() - mat[0].size()+1);C++){ //search area
            match=mat.size()*mat[0].size();
            for( r = 0;r<mat.size();r++){ //internal box
                for( c=0;c<mat[r].size();c++){//internal box
                    if(src[R+r][C+c] == mat[r][c]){
                         match--;   
                    }
                }
            }
        if(match==0)
            return "YES";
        }
    }
    
    return "NO";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int tests;
    cin>>tests;
    int R,C, r,c;
    for(int i =0;i<tests;i++){
        cin>>R>>C;
        //cout<<"RC "<<R<<" "<<C<<endl;
        vector< vector<int> > src;
        for(int j=0;j<R;j++){
            vector<int> a;
            for(int k=0;k<C;k++){
                char z;
                cin>>z;
                a.push_back(z-48);
            }      
            src.push_back(a);
        }
        
        cin>>r>>c;
        //cout<<"rc "<<r<<" "<<c<<endl;
        vector< vector<int> > mat;
        for(int j=0;j<r;j++){
            vector<int> a;
            for(int k=0;k<c;k++){
                char z;
                cin>>z;
                a.push_back(z-48);
            }   
            mat.push_back(a);
        }
        
        cout<<find_match(src, mat)<<endl;
        
        
        
        /*
        cout<<"t1 src"<<endl;
        for(auto f:src){
            for(auto g:f){
                cout<<g<<" ";
            }
            cout<<endl;
        }
        cout<<"t1 dst"<<endl;
        for(auto f:mat){
            for(auto g:f){
                cout<<g<<" ";
            }
            cout<<endl;
        }//*/
        src.clear();
        mat.clear();
    }
    
    return 0;
}

