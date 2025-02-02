#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge; cin >> node >> edge;

    /*
    // adjacency matrix
    int adj_mat[node][node];

    // adjacency matrix all value initialized to zero(0)
    memset(adj_mat, 0, sizeof(adj_mat));

    // input edge and assign value to 1
    while(edge--) {
        int a, b;   cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }

    // print adjacency matrix
    for(int i=0; i<node; i++) {
        for(int j=0; j<node; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    */

    /*
    // adjacency list
    vector<int> adj_list[node];
    while(edge--) {
        int a, b;   cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for(int i=0; i<node; i++) {
        cout << i << " -> ";
        for(int x : adj_list[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    */
   
    vector<pair<int,int>> edge_list;
    while(edge--) {
        int a, b;   cin >> a >> b;
        edge_list.push_back({a, b});
    }

    // for(pair<int,int> p : edge_list) {
    //     cout << "{" << p.first << "," << p.second << "}" << " , ";
    // }

    for(auto p : edge_list) {
        cout << "{" << p.first << "," << p.second << "}" << " , ";
    }

    return 0;
}