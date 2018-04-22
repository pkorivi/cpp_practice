#include <iostream>

bool myfunction (Player i,Player j) { 
    if(i.score == j.score){
        /*sort by names increasing order*/
     return i.name<j.name;   
    }
    return (i.score > j.score); //> for decreasing order
}

vector<Player> comparator(vector<Player> players) {
    std::sort (players.begin(), players.end(), myfunction);
    return players;
}


