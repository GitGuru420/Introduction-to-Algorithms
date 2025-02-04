#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[1005];
int parent[1005];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : v[par]) {
            if(vis[child] == false) {
                q.push(child);
                vis[child] = true;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src, dst;    cin >> src >> dst;
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    bfs(src);

    vector<int> path;
    int node = dst;
    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for(int p : path) {
        cout << p << " ";
    }

    return 0;
}