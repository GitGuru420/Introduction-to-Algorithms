#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void depth_first_search(int source) {
    cout << source << " ";
    visited[source] = true;
    for(int child : adj_list[source]) {
        if(!visited[child]) 
            depth_first_search(child);
    }
}
int main()
{
    int node, edge;     cin >> node >> edge;
    while(edge--) {
        int a, b;   cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    depth_first_search(0);

    return 0;
}   