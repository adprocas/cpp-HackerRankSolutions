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
#include <iomanip>

using namespace std;

class MinHeapCompare
    {
        public:

            bool operator() ( int x, int y ) const
            {
                return x > y;
            }
    };

class MaxHeapCompare
    {
        public:

            bool operator() ( int x, int y ) const
            {
                return x < y;
            }
    };

void rebalanceHeaps(vector<int> &minHeap, vector<int> &maxHeap) {
    //if sizes are off by more than one, move the value from the one
    //that is largest to the other heap
    if(abs((int)minHeap.size() - (int)maxHeap.size()) >= 2) {
        if(((int)minHeap.size() - (int)maxHeap.size()) >= 2) {
            int val = minHeap.front();
            maxHeap.push_back(val);
            push_heap(maxHeap.begin(), maxHeap.end(), MaxHeapCompare());
            
            pop_heap(minHeap.begin(), minHeap.end(), MinHeapCompare());
            minHeap.pop_back();
        } else {
            int val = maxHeap.front();
            minHeap.push_back(val);
            push_heap(minHeap.begin(), minHeap.end(), MinHeapCompare());
            
            pop_heap(maxHeap.begin(), maxHeap.end(), MaxHeapCompare());
            maxHeap.pop_back();
        }
    }
}

void insertIntoHeap(int a, vector<int> &minHeap, vector<int> &maxHeap) {
    //if the number is greater than the min number for min heap, add it there
    //else add to the max heap
    if(minHeap.size() > 0 && minHeap.front() <= a) {
        minHeap.push_back(a);
        push_heap(minHeap.begin(), minHeap.end(), MinHeapCompare());
    } else {
        maxHeap.push_back(a);
        push_heap(maxHeap.begin(), maxHeap.end(), MaxHeapCompare());
    }
    
    //rebalance
    rebalanceHeaps(minHeap, maxHeap);
}

float getMedium(vector<int> &minHeap, vector<int> &maxHeap) {
    //if the sizes are the same, take front from both and
    //divide by two, then return the result
    //else return a (float of a)
    if((int)minHeap.size() - (int)maxHeap.size() != 0) {
        if((int)minHeap.size() > (int)maxHeap.size()) {
            return (float)minHeap.front();
        } else {
            return (float)maxHeap.front();
        }
    } else {
        return (float)(minHeap.front() + maxHeap.front())/2;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    cout << fixed << setprecision(1);
    //minHeap holds large numbers that are sorted min first
    vector<int> minHeap;
    //maxHeap holds large numbers that are sorted max first
    vector<int> maxHeap;
    
    for(int x : a) {
        insertIntoHeap(x, minHeap, maxHeap);
        cout << getMedium(minHeap, maxHeap) << endl;
    }
    
    return 0;
}
