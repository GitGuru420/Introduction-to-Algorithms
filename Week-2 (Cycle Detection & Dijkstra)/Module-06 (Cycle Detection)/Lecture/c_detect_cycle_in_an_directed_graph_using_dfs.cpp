#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
bool vis[100];
int pathVis[100];
bool cycle;

void dfs(int src) {
    vis[src] = true;
    pathVis[src] = true;
    for(int child : adjList[src]) {
        if(vis[child] && pathVis[child])
            cycle = true;
        if(!vis[child]) {
            dfs(child);
        }
    }
    // return
    pathVis[src] = false;
}

int main()
{
    int n, e;   cin >> n >> e;
    while(e--) {
        int a, b;   cin >> a >> b;
        adjList[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));

    cycle = false;
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    if(cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}