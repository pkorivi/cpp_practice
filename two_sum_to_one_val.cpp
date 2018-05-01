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
/*
input
trips
(
money
number of flavours
cost of each flavour
)*numberoftrips
*/
/*Optimized code*/
int main(){
    int trips;
    cin>>trips;
    for(int i=0;i<trips;i++){
        int money, no_flavors,jthcost;
        unordered_map <int, int> costmap;
        cin>>money;
        cin>>no_flavors;
        for(int j=0;j<no_flavors;j++){
            cin>>jthcost;
            int compliment = money - jthcost;
            if(costmap.find(compliment) != costmap.end()){
                int k = costmap[compliment];
                j+1>k?cout<<k<<" "<<j+1<<endl:cout<<j+1<<" "<<k<<endl;
                continue;
            }
          costmap[jthcost] = j+1; //if compliment doesnt exist add the element to map for checking with next element
        }
    }
    return 0;
}





/*Junk code*/


struct icecream{
    int index;
    int cost;
};

void find_combination(int money, vector<icecream> flavor_cost){
    for(int i=0;i<flavor_cost.size();i++){
        for(int j = i+1;j<flavor_cost.size();j++){
            if(flavor_cost[i].cost+flavor_cost[j].cost == money){
                if(i<j)
                    cout<<flavor_cost[i].index<<" "<<flavor_cost[j].index<<endl;
                else
                    cout<<flavor_cost[j].index<<" "<<flavor_cost[i].index<<endl;
                return;
            }
        }
    }
}

void find_combination2(int money, vector<int> flavor_cost){
    unordered_map <int, int> costmap;
    for(int i=0;i<flavor_cost.size();i++){
        int compliment = money - flavor_cost[i];
        //if compliment exists in map
        if(costmap.find(compliment) != costmap.end()){
            int j = costmap[compliment];
            i+1>j?cout<<j<<" "<<i+1<<endl:cout<<i+1<<" "<<j<<endl;

            return;
        }
        costmap[flavor_cost[i]] = i+1; //if compliment doesnt exist add the element to map for checking with next element
    }
}



int main(){
    int trips;
    cin>>trips;
    for(int i=0;i<trips;i++){
        int money, no_flavors,ithcost;
        vector<int> flavor_cost;
        cin>>money;
        cin>>no_flavors;
        for(int j=0;j<no_flavors;j++){
            cin>>ithcost;
            flavor_cost.push_back(ithcost);
        }
        find_combination2(money,flavor_cost);
    }
    return 0;
}
