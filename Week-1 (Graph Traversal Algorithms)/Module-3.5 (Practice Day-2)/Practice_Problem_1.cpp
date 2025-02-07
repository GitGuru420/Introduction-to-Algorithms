#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int cnt = 0;

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
    int n;  cin >> n;   
    dfs(n);
    cout << cnt << endl;

    return 0;
}