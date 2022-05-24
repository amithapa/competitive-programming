# include <iostream>
# include <vector>
using namespace std;

void dfs(vector<int> graph[], int s, bool visited[]) {
    if (visited[s]) return;
    
    visited[s] = true;
    for (auto v: graph[s]) {
        dfs(graph, v, visited);
    }
}

bool isConnected(int n, vector<int> graph[], int s) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    dfs(graph, s, visited);

    for (int i=1; i < n; i++) {
        if(!visited[i]) return false;
    }
    return true;
}


int main() {
    int N = 6;
    vector<int> graph[N];

    graph[1].push_back(2);
    // graph[1].push_back(4);


    graph[2].push_back(1);
    graph[2].push_back(5);

    graph[3].push_back(2);
    graph[3].push_back(5);

    // graph[4].push_back(1);

    graph[5].push_back(2);
    graph[5].push_back(3);




    if (isConnected(N, graph, 1)) {
        cout << "Is connected\n";
    } else {
        cout << "Is not connected\n";
    }


    return 0;
}