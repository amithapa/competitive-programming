/*
Author:      Amit Thapa
Source:      Geek for geeks
Date:        28 May 2022 11:30PM
Link:        https://www.geeksforgeeks.org/check-if-a-given-graph-is-bipartite-using-dfs/?ref=lbp
Title:       Check if a given graph is Bipartite using DFS
*/

#include<iostream>
#include<vector>
// #include<pair>
#include<queue>
#include <climits>
using namespace std;

const int N = 6;
vector<pair<int, int>> adj[N];
int dist[N];
int parent[N];
bool visited[N];

void bfs(int start) {
    queue<int> q;
    q.push(start);

    dist[start] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(pair<int, int> node: adj[u]) {
            int v, weight;
            v = node.first;
            weight = node.second;

            if(visited[v]) continue;

            if(dist[v] > (weight + dist[u])) {
                dist[v] = weight + dist[u];
                parent[v] = u;
            }

            q.push(v);
        }
        visited[u] = true;
    }
}

void addEdge(int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
}

void printShortestPath(int u, int v) {
    vector<int> path;
    int result = v;
    

    while(result != -1) {
        path.push_back(result);
        result = parent[result];
    }
    reverse(path.begin(), path.end());

    cout << "Path: ";
    for(int x: path) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Distance: " << dist[v] << "\n";

}

void solve() {
    // Solution goes here
    addEdge(1,2,6);
    addEdge(1,4,1);
    addEdge(4,2,2);
    addEdge(2,5,2);
    addEdge(2,3,5);
    addEdge(4,5,1);
    addEdge(5,3,5);

    memset(parent, -1, sizeof(parent));


    for(int i = 1; i < N; i++) {
        dist[i] = INT_MAX;
    }

    bfs(1);

    for(int i=1; i < N; i++) {
        cout << i << " -> " << dist[i] << " [" << parent[i] << "]\n";
    }

    printShortestPath(1, 3);

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    return 0;
}