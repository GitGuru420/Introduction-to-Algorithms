#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
bool visited[100];
int level[100];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0; 

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adjList[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
            }
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
    int q;  cin >> q;
    while(q--) {
        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));
        int s, d;   cin >> s >> d;
        bfs(s);

        if(level[d] == -1)
            cout << "-1" << endl;
        else
            cout << level[d] << endl;
    }

    return 0;
}