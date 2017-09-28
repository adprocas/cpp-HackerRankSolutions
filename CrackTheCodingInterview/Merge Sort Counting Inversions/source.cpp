#include <bits/stdc++.h>

using namespace std;

//merge and sort halves
long long mergeHalves(vector<int> &arr, vector<int> &tmp, long long leftStart, long long rightEnd) {
    long long leftEnd = (rightEnd + leftStart) / 2;
    long long rightStart = leftEnd + 1;
    long long size = rightEnd - leftStart + 1;
    
    long long left = leftStart;
    long long right = rightStart;
    long long index = leftStart;
    
    long long count = 0;
    
    while(left <= leftEnd && right <= rightEnd) {
        if(arr[left] <= arr[right]) {
            tmp[index++] = arr[left++];
        } else {
            tmp[index++] = arr[right++];
            //Inversion happens for every right element that comes before a left element
            //in other words, it is out of place and to sort it, it needs to be inverted
            //at least once.
            //Every element left on the left side (in this case, all elements on the left after,
            //and including the currently checked element) would create another inversion
            //if we were to do this with just using inversion.
            //So, we add up the remaining elements on the left side, and increment by one
            //to include the current element checked.
            count += leftEnd - left + 1;
        }
    }
    
    while(left <= leftEnd) {
        tmp[index++] = arr[left++];
    }
    
    while(right <= rightEnd) {
        tmp[index++] = arr[right++];
    }
    
    index = leftStart;
    
    while(index <= rightEnd) {
        arr[index] = tmp[index];
        
        ++index;
    }
    
    return count;
}

//recursively merge and return counting from each merged half - add them up and return 
long long mergeSorter(vector<int> &arr, vector<int> &tmp, long long leftStart, long long rightEnd) {
    if(leftStart >= rightEnd) {
        return 0LL;
    }
    
    long long middle = (leftStart + rightEnd) / 2;
    long long count = 0;
    
    count += mergeSorter(arr, tmp, leftStart, middle);
    count += mergeSorter(arr, tmp, middle+1, rightEnd);
    
    count += mergeHalves(arr, tmp, leftStart, rightEnd);
    
    return count;
}

//helper method to get things started
long long mergeSort(vector<int> &arr) {
    vector<int> tmp(arr);
    
    return mergeSorter(arr, tmp, 0, arr.size() - 1);
}

long long countInversions(vector<int> &arr) {
    return mergeSort(arr);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long long result = countInversions(arr);
        cout << result << endl;
    }
    return 0;
}
