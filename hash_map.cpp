#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    std::unordered_map<std::string, int> map;
    for(auto s : magazine){
        map[s] +=1;
        /*if(map[s] == 1) //If an element doesnt exist in map, it creates a dummy elemt with 0 value in map. so we need
            map[s] +=1;   //so we need to increment it to 1, if its 1 already make higher. 
        else
            map[s] +=1;*/
    }

    for(auto v : ransom){
        if(map[v] > 0){
            map[v] -=1;
        }
        else
            return 0;
    }
    return 1;//(no_str==0?1:0);
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

