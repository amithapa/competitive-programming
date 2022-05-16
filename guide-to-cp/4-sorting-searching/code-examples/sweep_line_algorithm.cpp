# include <iostream>
# include <vector>
using namespace std;

int main() {
    int n =4;
    int in_time[] = {6, 4, 10, 2};
    int out_time[] = {9, 7, 12, 9};

    sort(in_time, in_time+n);
    sort(out_time, out_time+n);
    int counter = 0, best = -1, i=0, j=0;


    while(i < n && j < n) {
        cout << in_time[i] << " " << out_time[j] << "\n";
        if(in_time[i] < out_time[j]) {
            counter++;
            i++;
        } else if(in_time[i] > out_time[j]) {
            counter--;
            j++;
        } else {
            i++;
            j++;
        }
        best = max(counter, best);
    }

    cout << best << "\n";

    return 0;
}