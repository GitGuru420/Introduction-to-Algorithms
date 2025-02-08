#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
vector<int> connected_node;

void bfs(int s) {
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adjList[par]) {
            connected_node.push_back(child);
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
    int node;  cin >> node;
    bfs(node);
    cout << connected_node.size();

    return 0;
}