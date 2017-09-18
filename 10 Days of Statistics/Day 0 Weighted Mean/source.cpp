#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>      // std::setprecision
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> multipliers;
    
    for(int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        
        multipliers.push_back(val);
    }
    
    float totalVal = 0;
    float divVal = 0;
    
    for(int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        
        divVal += val;
        totalVal += val * multipliers[i];
    }
    
    cout << fixed;
    cout << setprecision(1);
    cout << totalVal / divVal << endl;
    
    return 0;
}
