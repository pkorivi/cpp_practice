#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Graph {
    public:
        vector< vector<int> > graph;
        Graph(int n) {
            graph.clear();
            for(int i=0;i<n;i++){
                vector<int> children;
                graph.push_back(children);
            }
        }

        void add_edge(int u, int v) {
            graph[u].push_back(v); //adding children
             graph[v].push_back(u);
        }

        vector<int> shortest_reach(int start) {
            vector <int> dists(graph.size(),-1);
            queue<int> next_to_visit;
            unordered_set<int> visited;
            next_to_visit.push(start);
            dists[start]=0;
            visited.insert(start);

            while(!next_to_visit.empty()){
                int node = next_to_visit.front();
                next_to_visit.pop(); //remove node from list
                for(auto child : graph[node]){
                    if(visited.find(child)==visited.end()){ //child is not visited
                        next_to_visit.push(child);
                        visited.insert(child);
                        dists[child] = dists[node]+6;
                    }
                }
            }
            return dists;
        }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
