#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
vector<int> components;
int cnt;

void dfs(int src) {
    cnt++;
    visited[src] = true;
    for(int child : adj_list[src]) {
        if(!visited[child]) {
            dfs(child);
        }
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
    for(int i=0; i<node; i++) {
        if(!visited[i]) {
            cnt = 0;
            dfs(i);
            components.push_back(cnt);
        }
    }
    
    sort(components.begin(), components.end());
    for(int val : components)
        cout << val << " ";
    

    return 0;
}