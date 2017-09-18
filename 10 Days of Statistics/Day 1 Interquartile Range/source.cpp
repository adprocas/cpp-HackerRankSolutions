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
    vector<int> tmpNums;
    
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        
        tmpNums.push_back(num);
    }
    
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        
        for(int x = 0; x < num; ++x) {
            nums.push_back(tmpNums[i]);
        }
    }
    
    sort(nums.begin(), nums.end());
    
    n = nums.size();
    
    int middle = n/2;
    float firstQuart = 0;
    float thirdQuart = 0;
    
    cout << fixed << setprecision(1);
    
    if((n/2) % 2 == 0) {
        firstQuart = ((float)nums[middle/2] + (float)nums[(middle/2)-1])/2;
    } else {
        firstQuart = (float)nums[middle/2];
    }
    
    if((n/2) % 2 == 0) {
        if(n % 2 == 0) {
            thirdQuart = ((float)nums[middle + middle/2] + (float)nums[middle + (middle/2) - 1])/2;
        } else {
            thirdQuart = ((float)nums[middle + middle/2] + (float)nums[middle + (middle/2) + 1])/2;
        }
    } else {
        thirdQuart = (float)nums[(middle/2 + middle)+1];
    }
        
    cout << (thirdQuart - firstQuart) << endl;
    
    return 0;
}
