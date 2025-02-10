#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> adjList[200005];
        bool visited[200005];
    
        void dfs(int source) {
            visited[source] = true;
            for(int child : adjList[source]) {
                if(!visited[child]) 
                    dfs(child);
            }
        }
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            // convert edge list to adjList
            for(int i=0; i<edges.size(); i++) {
                int a = edges[i][0];
                int b = edges[i][1];
                adjList[a].push_back(b);
                adjList[b].push_back(a);
            }
            memset(visited, false, sizeof(visited));
            dfs(source);
            if(visited[destination]) 
                return true;
            else
                return false;
        }
    };

int main()
{

    return 0;
}