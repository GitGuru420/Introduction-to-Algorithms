#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int node, edge;     cin >> node >> edge;
    vector<int> adjList[node];
    // vector<vector<int>> adjList(node);

    while(edge--) {
        int a, b;   cin >> a >> b;
        adjList[a].push_back(b);   // directed
        adjList[b].push_back(a);   // undirected
    }

    for(int i=0; i<node; i++) {
        cout << i << " -> ";
        for(int child : adjList[i]) {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}