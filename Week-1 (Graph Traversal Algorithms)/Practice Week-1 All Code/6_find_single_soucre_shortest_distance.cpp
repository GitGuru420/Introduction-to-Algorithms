#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
bool visited[100];
int level[100];

void breadth_first_search(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    level[source] = 0;

    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        for(int child : adjList[parent]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
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
    memset(level, -1, sizeof(level));
    int source, destination;     cin >> source >> destination;
    breadth_first_search(source);

    cout << source << " to " << destination << " distance: " << level[destination] << endl;

    return 0;
}