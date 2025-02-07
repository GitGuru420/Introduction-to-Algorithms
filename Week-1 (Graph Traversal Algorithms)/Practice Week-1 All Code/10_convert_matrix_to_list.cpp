/*
Problem 1: Convert Adjacency Matrix to Adjacency List

Problem Statement:
Given an n × n adjacency matrix representing an unweighted graph, convert it into an adjacency list representation.

Example:

Input:
3
0 1 1
1 0 0
1 0 0

Output:
0 -> 1 2
1 -> 0
2 -> 0
*/

#include <bits/stdc++.h>
using namespace std;

void matrixToList(int adjMat[][100], int n) {
    vector<int> adjList[n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(adjMat[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << i << " -> ";
        for(int val : adjList[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;  cin >> n;
    int adjMat[100][100];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> adjMat[i][j];
        }
    }
    matrixToList(adjMat, n);

    return 0;
}