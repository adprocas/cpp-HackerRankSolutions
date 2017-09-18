#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A, greater <int>> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A, greater <int>> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<int, int> numbers;
    vector<int> nums;
    
    int n;
    float meanAdded = 0;
    float medianAdded = 0;
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        int insert;
        cin >> insert;
        
        meanAdded += insert;
        
        map<int, int>::iterator it = numbers.find(insert);
        
        if(it != numbers.end()) {
            it->second++;
        } else {
            numbers.insert(pair<int, int>(insert, 1));
        }
        
        nums.push_back(insert);
    }
    
    sort(nums.begin(), nums.end());
    
    cout << fixed;
    cout << setprecision(1);
    
    cout << meanAdded/n << endl;
    
    if(n % 2 == 0) {
        cout << (float)(nums[(int)(n/2)] + nums[(int)(n/2)-1])/2 << endl;
    } else {
        cout << nums[(int)(n/2)] << endl;
    }
    
    multimap<int, int, greater <int>> dst = flip_map(numbers);
    
    cout << dst.begin()->second << endl;
    
    return 0;
}
