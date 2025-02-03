#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000];
bool visited_node[1000];

void breadth_first_search(int source) {
    queue<int> q;
    q.push(source);
    visited_node[source] = true;
    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        for(int child : adj_list[parent]) {
           if(!visited_node[child]) {
                q.push(child);
                visited_node[child] = true;
           }
        }
    }
}

int main()
{
    int node, edge; cin >> node >> edge;
    while(edge--) {
        int a, b;   cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited_node, false, sizeof(visited_node));
    breadth_first_search(0);

    int check_node; cin >> check_node;
    if(visited_node[check_node])
        cout << "Yes, visited" << endl;
    else
        cout << "No, not visited" << endl;

    return 0;
}