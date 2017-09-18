#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> nums;
    
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    
    int middle = n/2;
    
    if((n/2) % 2 == 0) {
        cout << ((float)nums[middle/2] + (float)nums[(middle/2)-1])/2 << endl;
    } else {
        cout << (float)nums[middle/2] << endl;
    }
    
    if(n % 2 == 0) {
        cout << ((float)nums[middle] + (float)nums[(middle) - 1])/2 << endl;
        
    } else {
        cout << (float)nums[middle] << endl;
    }
    
    if((n/2) % 2 == 0) {
        if(n % 2 == 0) {
            cout << ((float)nums[middle + middle/2] + (float)nums[middle + (middle/2) - 1])/2 << endl;
        } else {
            cout << ((float)nums[middle + middle/2] + (float)nums[middle + (middle/2) + 1])/2 << endl;
        }
    } else {
        cout << (float)nums[middle/2 + middle] << endl;
    }
    
    return 0;
}
