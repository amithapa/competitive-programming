/*
Author:      Amit Thapa
Source:      Geek for geeks
Date:        30 May 2022 11:30PM
Link:        https://codeforces.com/problemset/problem/1549/B
Title:       Chess Board
*/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

const int N = 200005;

vector<int> adj[N];
bool visited[N];


void dfs(int source, int destination, int matrix[4][4]) {

}



void solve() {
    // Solution goes here
    int n;
    cin >> n;
    int board[2][n]; 
    string mine, gregor;
    for(int i=0; i < 2; i++) {
        for(int j=0; j<n; j++)
            board[i][j] = 0;
    }
    cin >> gregor;
    cin >> mine;
    for(int i=0; i < n; i++) {
        board[0][i] = gregor[i] - 48;
        board[1][i] = mine[i] - 48;
    }
    int moved = 0;
    for(int i=0; i < n; i++) {
        if(board[1][i] == 0) continue;

        if(board[0][i] == 0) {
            moved++;
            continue;
        }
        if(i != 0 && board[0][i-1] !=0) {
            moved++;
            board[0][i-1] = 0;
        } 
        if(i != (n-1) && board[0][i+1] !=0) {
            moved++;
            board[0][i+1] = 0;
        } 
    }

    cout << moved << "<--\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while(t--)  solve();

    return 0;
}