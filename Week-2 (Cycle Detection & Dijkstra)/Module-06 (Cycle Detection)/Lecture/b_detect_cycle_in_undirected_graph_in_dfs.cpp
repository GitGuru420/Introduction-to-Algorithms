#include <bits/stdc++.h>
using namespace std;
bool vis[100];
vector<int> adjList[100];
int parent[100];
bool cycle;

void dfs(int src) {
    vis[src] = true;
    for(int child : adjList[src]) {
        if(vis[child] && parent[src] != child) 
                cycle = true;
        if(!vis[child]) {
            parent[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    int n, e;   cin >> n >> e;
    while(e--) {
        int a, b;   cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    // for(int i=0; i<n; i++) {
    //     cout << i << " parent -> " << parent[i] << endl;
    // }

    if(cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;
        
    return 0;
}