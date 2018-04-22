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

int find_conn(vector< vector<int> > &grid, int i, int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size())
        return 0;
    if (grid[i][j]==0)
        return 0;
    
    int count = grid[i][j]--; //post decrement, initially count is 1 then g[i][j] is made 0 so that its not counted again
    count += find_conn(grid,i-1,j-1);
    count += find_conn(grid,i-1,j);
    count += find_conn(grid,i-1,j+1);
    count += find_conn(grid,i,j-1);
    count += find_conn(grid,i,j+1);
    count += find_conn(grid,i+1,j-1);
    count += find_conn(grid,i+1,j);
    count += find_conn(grid,i+1,j+1);
    return count;
}

int get_biggest_region(vector< vector<int> > grid) {
    vector< vector<int> > connections;
    int max_val =0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();i++){
            max_val = max(max_val,find_conn(grid,i,j));
        }
    } 
    return max_val;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}

