#include <iostream>
using namespace std;

void print_array(int arr[100], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int getMaxNumber(int arr[100], int n) {
    int max_number = 0;

    for(int i=0; i < n; i++) {
        max_number = max(arr[i], max_number);
    }

    return max_number;
}

void count_sort(int arr[100], int n) {
    int m = getMaxNumber(arr, n), k=0;
    int bucket[m+1];
    
    memset(bucket, 0, sizeof(bucket));

    for(int i=0; i < n; i++) {
        bucket[arr[i]] += 1;
    }
    
    for(int i=0; i <= m; i++) {
        for(int j=0; j < bucket[i]; j++) {
            arr[k] = i;
            k++;
        }
    }

}

int main() {
    int arr[] = {4,3,8,1,9,4,5,6};

    print_array(arr, 8);

    count_sort(arr, 8);

    print_array(arr, 8);

    return 0;
}