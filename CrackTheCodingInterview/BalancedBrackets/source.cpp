#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
    map<char, int> bracketMap;
    
    bracketMap.insert(make_pair('{', 1));
    bracketMap.insert(make_pair('}', 2));
    bracketMap.insert(make_pair('[', 3));
    bracketMap.insert(make_pair(']', 4));
    bracketMap.insert(make_pair('(', 5));
    bracketMap.insert(make_pair(')', 6));
    
    if(expression.size() == 0)
        return true;
    
    if(expression.size() % 2 != 0)
        return false;
    
    vector<int> bv;
    int balanceCount = 0;
    
    for(int i = 0; i < expression.size(); ++i) {
        int val = bracketMap.find(expression[i])->second;
        bv.push_back(val);
        
        if(val % 2 == 0)
            balanceCount++;
        else
            balanceCount--;
    }
    
    if(balanceCount != 0)
        return false;
    
    for(int i = 0; i < bv.size(); ++i) {
        int val = bv.at(i);
        
        //end bracket exists
        if(bv.at(i) % 2 == 0) {
            if(i <= 0) {
                return false;
            }
            
            //if the one before is the closing bracket
            //then erase the two, and start from just before
            //the one before
            //otherwise it's a lonely bracket
            if(bv.at(i-1) == val - 1) {
                bv.erase(bv.begin() + i);
                bv.erase(bv.begin() + (i-1));
            } else {
                return false;
            }
            
            if(i - 2 <= 0) {
                i = 0;
            }
            else {
                i -= 2;
            }
        }
    }
    
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
