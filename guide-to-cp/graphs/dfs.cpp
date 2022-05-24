# include <iostream>
# include <vector>
using namespace std;

void dfs(vector<int> graph[], int s, bool visited[]) {
    if (visited[s]) return;
    
    visited[s] = true;
    cout << s << " ";
    for (auto v: graph[s]) {
        dfs(graph, v, visited);
    }
}


int main() {
    int N = 6;
    vector<int> graph[N];

    graph[1].push_back(2);
    graph[1].push_back(4);


    graph[2].push_back(1);
    graph[2].push_back(5);

    graph[3].push_back(2);
    graph[3].push_back(5);

    graph[4].push_back(1);

    graph[5].push_back(2);
    graph[5].push_back(3);

    bool visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    dfs(graph, 1, visited);
    cout << "\n";
    return 0;
}