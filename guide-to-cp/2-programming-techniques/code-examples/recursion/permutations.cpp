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

void print_permuations(vector<int> permutation, int n, bool chosen[]) {
    if (permutation.size() == n) {
        print_subset(permutation);
        return;
    }
    for (int i=1; i <= n; i++) {
        if (chosen[i]) {
            continue;
        }
        chosen[i] = true;
        permutation.push_back(i);
        print_permuations(permutation, n, chosen);
        chosen[i] = false;
        permutation.pop_back();
    }


}


int main() {
    vector<int> permutation;
    bool chosen[100] = {false};
    int n;

    cin >> n;

    print_permuations(permutation, n, chosen);

    return 0;
}