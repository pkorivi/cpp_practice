#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

//This has code to take input from the screen, parse, perform string compare etc
//Cons:: Takes too long when input is very big, timeout, 

std::vector<std::string> split(std::string str,std::string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
   vector <string> names;
   string line;
   getline (cin, line);
   int num_of_lines = stoi(line);
   while (getline (cin, line)){
       vector <string> v;
       v = split(line," ");
       if(v[0].compare("add") == 0)
           names.push_back(v[1]);
        else if(v[0].compare("find") ==0){
            int count =0;
            for(int i =0;i<names.size();i++){
                int leng=v[1].length();
                if(v[1].compare(0,leng,names[i],0,leng) == 0 )
                    count++;
            }
            cout<<count<<endl;
        }    
   }
   //std::cout << "No more lines" << std::endl;
   return 0;
}

