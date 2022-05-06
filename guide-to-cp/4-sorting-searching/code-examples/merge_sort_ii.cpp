#include <iostream>
using namespace std;

void print_array(int arr[100], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void merge(int arr[], int start, int middle, int end) {
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int arr1[n1+1], arr2[n2+1];
    
    int i, j, k;
    for (i=0; i<n1; i++)
        arr1[i] = arr[start+i];
    
    for (j=0; j<n2; j++)
        arr2[j] = arr[middle+j+1];

    i=j=0;
    k=start;
    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            arr[k++] = arr1[i];
            i++;
        } else {
            arr[k++] = arr2[j];
            j++;
        }
    }

    while(i < n1) {
        arr[k++] = arr1[i];
        i++;
    }
    while(j < n2) {
        arr[k++] = arr2[j];
        j++;
    }

}


void merge_sort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int middle = (start + end) / 2;
    merge_sort(arr, start, middle);
    merge_sort(arr, middle+1, end);
    merge(arr, start, middle, end);
}

int main() {
    int arr[] = {4,3,8,1,9,4,5,6};

    print_array(arr, 8);

    merge_sort(arr, 0, 7);

    print_array(arr, 8);

    return 0;
}