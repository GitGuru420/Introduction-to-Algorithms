#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000];
int visited_node[1000];
int level[1000];
int parent_path[1000];

void breadth_first_search(int source) {
    queue<int> q;
    q.push(source);
    visited_node[source] = true;
    level[source] = 0;
    // parent_path[source] = -1; --> eii line na likhleo chole, 
    // cz aage e define kora ache memset diye
    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        for(int child : adj_list[parent]) {
            if(!visited_node[child]) {
                q.push(child);
                visited_node[child] = true;
                level[child] = level[parent] + 1;
                parent_path[child] = parent;
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
    memset(parent_path, -1, sizeof(parent_path));
    int source, destination;    cin >> source >> destination;
    breadth_first_search(source);
    
    // for(int i=0; i<node; i++) {
    //     cout << i << " parent -> " << parent_path[i] << endl;
    // }

    int node1 = destination;
    // while(node1 != -1) {
    //     cout << node1 << " ";
    //     node1 = parent_path[node1];
    // }
    
    vector<int> path;
    while (node1 != -1) {
        path.push_back(node1);
        node1 = parent_path[node1];
    }
    reverse(path.begin(), path.end());
    for(int x : path) {
        cout << x << "->";
    }
    

    return 0;
}