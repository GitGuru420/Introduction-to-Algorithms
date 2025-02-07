// Find out what is the shortest distance between 0 to 3 using BFS
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
bool visited[100];
int level[100];
int parentTrack[100];

void breadth_first_search(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    level[source] = 0;

    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        for(int child : adjList[parent])  {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
                parentTrack[child] = parent;
            }
        }
    }
}

int main()
{
    int node, edge;   cin >> node >> edge;
    while(edge--) {
        int a, b;   cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parentTrack, -1, sizeof(parentTrack));
    breadth_first_search(0);
    
    int vertex = 2;
    vector<int> path;
    while(vertex != -1) {
        path.push_back(vertex);
        vertex = parentTrack[vertex];
    }
    reverse(path.begin(), path.end());
    for(int p : path) {
        cout << p << " ";
    }

    return 0;
}