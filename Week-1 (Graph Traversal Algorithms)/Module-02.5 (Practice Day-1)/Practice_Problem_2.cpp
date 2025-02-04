#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000];
bool visited_node[1000];
int level[1000];

void breadth_first_search(int source) {
    queue<int> q;
    q.push(source);
    visited_node[source] = true;
    level[source] = 0;

    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        for(int child : adj_list[parent]) {
            if(!visited_node[child]) {
                q.push(child);
                visited_node[child] = true;
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
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited_node, false, sizeof(visited_node));
    memset(level, -1, sizeof(level));
    breadth_first_search(0);

    int l;  cin >> l;
    vector<int> level_node;
    for(int i=0; i<node; i++) {
        if(level[i] == l) {
            level_node.push_back(i);
        }
    }
    sort(level_node.begin(), level_node.end(), greater<int>());
    for(int node : level_node) {
        cout << node << " ";
    }

    return 0;
}