# include<iostream>
# include<vector>

using namespace std;


int search(int col[100], int daig_left[100], int diag_right[100], int n, int y) {
    if (y == n) {
        return 1;
    }
    int count = 0;
    for (int x=0; x < n; x++) {
        if (col[x] || daig_left[x+y] || diag_right[x-y+n-1]) {
            continue;
        }

        col[x] = daig_left[x+y] = diag_right[x-y+n-1] = 1;
        count += search(col, daig_left, diag_right, n, y+1);
        col[x] = daig_left[x+y] = diag_right[x-y+n-1] = 0;
    }
    return count;

}

int main() {
    int n;
    vector<int> count;    
    
    count.push_back(0);

    int col[100] = {0}, daig_left[100] = {0}, diag_right[100] = {0};
    cin >> n;

    cout << search(col, daig_left, diag_right, n, 0) << "\n";
    // cout << count[0] << "\n";

    return 0;
}