#include <iostream>
#include <vector>
using namespace std;

void print_subset(vector<int> subset) {
    cout << "{";
    for (int i=0; i < subset.size(); i++) {
        cout << subset[i];
        if (i != (subset.size() - 1)) {
            cout << ", ";
        }
    }
    cout << "}\n";
}

void search(vector<int> subset, int k, int n) {
    if (k == (n+1)) {
        print_subset(subset);
        return;
    }
    subset.push_back(k);
    search(subset, k+1, n);
    subset.pop_back();
    search(subset, k+1, n);
}


int main() {
    vector<int> subset;
    int n;
    cin >> n;

    search(subset, 1, n);

    return 0;
}