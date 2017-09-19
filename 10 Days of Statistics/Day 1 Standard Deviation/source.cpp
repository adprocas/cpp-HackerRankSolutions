#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

float getMean(vector<int> v) {
    float total = 0;
    
    for(int i = 0; i < v.size(); ++i) {
        total += v[i];
    }
    
    return (float)(total/v.size());
}

float getSD(vector<int> v) {
    float mean = getMean(v);
    float tot = 0;
    
    for(int i = 0; i < v.size(); ++i) {
        tot += pow((v[i] - mean), 2);
    }
    
    return (float)sqrt(tot/v.size());
}

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
    
    float sd = getSD(nums);
    
    cout << fixed;
    cout << setprecision(1);
    cout << sd << endl;
    
    return 0;
}
