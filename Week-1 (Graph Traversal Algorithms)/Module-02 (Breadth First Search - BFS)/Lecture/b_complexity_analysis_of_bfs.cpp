#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src) {
    queue<int> q;   // Space Complexity: O(V)
    q.push(src);
    visited[src] = true;

    while(!q.empty()) { // O(V)
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for(int child : adj_list[parent]) { // O(E)
            if(visited[child] == false) {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}
// Final Complexity: O(V+E) // V->Vertices, E->Edge

int main()
{
    int n, e;   cin >> n >> e;
    while(e--) {
        int a, b;   cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    bfs(0);

    return 0;
}