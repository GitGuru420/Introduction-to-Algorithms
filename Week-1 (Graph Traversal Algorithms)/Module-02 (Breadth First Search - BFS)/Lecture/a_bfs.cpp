#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        // step-1: ber kore ana
        int parent = q.front();
        q.pop();

        // step-2: oi node niye kaj kora
        cout << parent << " ";

        // step-3: children gulo push kora
        for(int child : adj_list[parent]) {
            if(visited[child] == false) {
                q.push(child);
                visited[child] = true;
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
    bfs(0); // let source node -> 0

    return 0;
}