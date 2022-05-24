# include <iostream>
# include <vector>
# include <queue>
using namespace std;

void bfs(vector<int> graph[], int s, bool visited[]) {
    queue<int> q;
    q.push(s);
    int u;

    while (!q.empty()) {
        u = q.front();
        q.pop();
        
        cout << u << " ";
        for(auto v: graph[u]) {
            if (visited[v]) continue;
            q.push(v);
        }
        visited[u] = true;
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

    bfs(graph, 1, visited);
    cout << "\n";
    return 0;
}