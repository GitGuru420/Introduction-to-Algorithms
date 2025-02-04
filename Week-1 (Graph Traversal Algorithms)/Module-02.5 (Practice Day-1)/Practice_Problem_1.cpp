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

    int q;  cin >> q;
    while(q--) {
        memset(visited_node, false, sizeof(visited_node));
        memset(level, -1, sizeof(level));
        int src, dst;   cin >> src >> dst;
        breadth_first_search(src);
        if(level[dst] == -1)
            cout << "-1" << endl;
        else
            cout << level[dst] << endl;
    }
    
    return 0;
}