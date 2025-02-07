#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];
bool visited[1000];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    vector<int> connect;
    while(!q.empty()) {
        int par = q.front();
        q.pop();
        
        for(int child : adjList[par]) {
            if(!visited[child]) {
                connect.push_back(child);
            }
        }
    }
    if(connect.size() == 0) {
        cout << "-1" << endl;
        return;
    }
    sort(connect.begin(), connect.end(), greater<int>());
    for(int val : connect) {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    int n, e;   cin >> n >> e;
    while(e--) {
        int a, b;   cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int q;  cin >> q;
    while(q--) {
        int node;   cin >> node;
        memset(visited, false, sizeof(visited));
        bfs(node);
    }

    return 0;
}