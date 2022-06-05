/*
Author:      Amit Thapa
Source:      Geek for geeks
Date:        29 May 2022 03:30PM
Link:        https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/?ref=lbp
Title:       Find Mother vertex
*/
#include<iostream>
#include<vector>

using namespace std;

const int N = 10005;

vector<int> adj[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void dfs(int u, vector<bool> &visited) {
    visited[u] = true;

    for(int v: adj[u]) {
        if(visited[v]) continue;
        dfs(v, visited);
    }
}

int findMotherVertex(int n) {
    int v = 0;

    vector<bool> visited(n, false);


    for(int i=0; i < n; i++) {
        if(visited[i]) continue;
        dfs(i, visited);
        v = i;
    }

    fill(visited.begin(), visited.end(), false);
    dfs(v, visited);

    for(int i=0; i < n; i++) {
        if(!visited[i]) return -1;
    }
    return v;
}

void solve() {
    int n = 8;
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(4, 1);
    addEdge(5, 2);
    addEdge(5, 6);
    addEdge(6, 4);
    addEdge(6, 0);

    cout << findMotherVertex(n) << "\n";

}

int main() {
    solve();
    return 0;
}