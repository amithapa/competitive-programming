#include <iostream>
using namespace std;

void print_array(int arr[100], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void merge(int arr[100], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left +1;
    int n2 = right - middle;
    int left_arr[n1], right_arr[n2];

    for(i=0; i<n1; i++) {
        left_arr[i] = arr[i+left];
    }
    // print_array(left_arr, n1);


    for(j=0; j<n2; j++) {
        right_arr[j] = arr[middle+j+1];
        // cout << right_arr[j] << " ";
    }
    // print_array(right_arr, n2);
    // cout << left << " " << middle << " <-> " << right << "\n";

    i=0;
    j=0;
    k=left;
    while (i < n1 && j < n2) {
        if(left_arr[i] < right_arr[j]) {
            // cout << "swapping " << left_arr[i] << " " << right_arr[j] << " | "<< arr[k] << "\n";
            arr[k] = left_arr[i];
            
            i++;
        } else {
            // cout << "swapping\n";
            arr[k] = right_arr[j];
            j++;
        }

        k++;
    }
    
    while(i<n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
   
    while(j<n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    
}

void merge_sort(int arr[100], int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = (left + right) / 2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle+1, right);
    merge(arr, left, middle, right);
}

int main() {
    int arr[] = {1,3,8,2,9,2,5,6};

    print_array(arr, 8);

    merge_sort(arr, 0, 8);

    print_array(arr, 8);

    return 0;
}