# include <iostream>
# include <vector>
# include <queue>
using namespace std;

void calculate_distance(int s, int n, vector<int> graph[]) {
    bool visited[n];
    int distance[n];
    for(int i=0; i < n; i++) {
        visited[i] = false;
        distance[i] = 0;
    }
    queue<int> q;
    distance[s] = 0;
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: graph[u]) {
            if(visited[v]) continue;
            distance[v] = distance[u] + 1;
            visited[v] = true;
            q.push(v);
        }
    }

    for(int i=1; i < n; i++) {
        cout << i << " -> " << distance[i] << "\n";
    }


}

int main() {
    int n = 6;
    vector<int> graph[n];
    graph[1].push_back(2);
    graph[1].push_back(4);


    graph[2].push_back(1);
    graph[2].push_back(5);

    graph[3].push_back(2);
    graph[3].push_back(5);

    graph[4].push_back(1);

    graph[5].push_back(2);
    graph[5].push_back(3);

    calculate_distance(1, n, graph);

    return 0;
}