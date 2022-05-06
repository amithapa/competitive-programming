#include<iostream>
using namespace std;

int max_sum_subarray(int numbers[100], int n) {
    int best = 0;
    int total = 0;

    for(int i=0; i < n; i++) {
        total = max(numbers[i], total+numbers[i]);
        best = max(total, best);
    }

    return best;
}

int main() {
    int numbers[] = {-1, 2, 4, -3, 5, 2, -5, 2};

    cout << max_sum_subarray(numbers, 8) << "\n";

    return 0;
}