#include <iostream>
#include <algorithm>
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

int main() {
    vector<int> permutation;
    int n;
    cin >> n;

    for (int i=1; i <= n; i++) {
        permutation.push_back(i);
    }


    do {
        // process permutation
        print_subset(permutation);
    } while(next_permutation(permutation.begin(), permutation.end()));

    return 0;
}