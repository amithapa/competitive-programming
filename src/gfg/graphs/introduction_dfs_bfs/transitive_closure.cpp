/*
Author:      Amit Thapa
Source:      Geek for geeks
Date:        30 May 2022 11:30PM
Link:        https://www.geeksforgeeks.org/transitive-closure-of-a-graph-using-dfs/
Title:       Transitive Closure of a Graph using DFS
*/

#include<iostream>
#include<vector>
using namespace std;

const int N = 10005;

vector<int> adj[N];
bool visited[N];


void dfs(int source, int destination, int matrix[4][4]) {
   matrix[source][destination] = 1;
   cout << source << " " << destination << "\n";

   for(int x: adj[destination]) {
       if(matrix[source][x]) continue;
       dfs(source, x, matrix);
   }
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void solve() {
    // Solution goes here
    int n = 4;
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);

    int matrix[4][4];

    for(int i=0; i < n; i++) {
        memset(matrix[i], 0, n*sizeof(int));
    }

    for(int i=0; i < n; i++) {
        dfs(i, i, matrix);
    }

    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    return 0;
}