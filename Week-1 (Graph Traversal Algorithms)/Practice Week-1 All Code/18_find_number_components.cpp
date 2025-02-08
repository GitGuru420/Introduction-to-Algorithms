#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
bool visited[100];

void dfs(int src) {
    visited[src] = true;
    
    for(int child : adjList[src]) {
        if(!visited[child]) {
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
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}