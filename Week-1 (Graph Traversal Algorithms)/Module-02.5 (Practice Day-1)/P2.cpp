#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool visited[100005];
int parent[100005];

void bfs(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    
    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n, e;   cin >> n >> e;
    while(e--) {
        int a, b;   cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    int src = 1, dst = n;
    bfs(src);

    vector<int> path;
    int node = dst;
    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    if(!visited[dst]) 
        cout << "IMPOSSIBLE" << endl;
    else {
        cout << path.size() << endl;
        for(int x : path) {
            cout << x << " ";
        }
    }
    return 0;
}