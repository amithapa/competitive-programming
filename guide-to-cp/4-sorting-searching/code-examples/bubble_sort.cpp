#include <iostream>
using namespace std;

void print_array(int arr[100], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void bubble_sort(int arr[100], int n) {
    int temp;
    for(int i=0; i < n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // temp = arr[j];
                // arr[j] = arr[j+1];
                // arr[j+1] = temp;
                swap(arr[j], arr[j+1]);
            }
        }
    }

}

int main() {
    int arr[] = {1,3,8,2,9,2,5,6};

    print_array(arr, 8);

    bubble_sort(arr, 8);

    print_array(arr, 8);

    return 0;
}