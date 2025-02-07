#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
bool visited[100];

void breadth_first_search(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for(int child : adjList[parent]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}

int main()
{
    int node, edge;     cin >> node >> edge;
    while(edge--) {
        int a, b;   cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    int source;     cin >> source;
    breadth_first_search(source);

    return 0;
}