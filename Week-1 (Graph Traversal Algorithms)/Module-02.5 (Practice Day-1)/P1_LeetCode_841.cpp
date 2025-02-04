#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool visited[1005];
    void bfs(int source, vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()) {
            int parent = q.front();
            q.pop();

            for(int child : rooms[parent]) {
                if(!visited[child]) {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(visited, false, sizeof(visited));
        bfs(0, rooms);
        for(int i=0; i<rooms.size(); i++) {
            if(!visited[i]) 
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}