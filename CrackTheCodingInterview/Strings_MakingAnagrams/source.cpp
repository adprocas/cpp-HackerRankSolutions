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

int number_needed(string a, string b) {
    map<char, int> mapA;
    map<char, int> mapB;
    std::map<char, int> totalMap;
    
    for ( int i = 0 ; i < a.length(); i++)
    {
        std::map<char, int>::iterator it = mapA.find(a[i]);
        if( it == mapA.end() ) {
            mapA.insert(make_pair(a[i], 1));
        } else {
            it->second++;
        }
        
        std::map<char, int>::iterator Ait = totalMap.find(a[i]);
        if( Ait == totalMap.end() ) {
            totalMap.insert(make_pair(a[i], 1));
        } else {
            Ait->second++;
        }
    }
    
    for ( int i = 0 ; i < b.length(); i++)
    {
        std::map<char, int>::iterator it = mapB.find(b[i]);
        if( it == mapB.end() ) {
            mapB.insert(make_pair(b[i], 1));
        } else {
            it->second++;
        }
        
        std::map<char, int>::iterator Ait = totalMap.find(b[i]);
        if( Ait == totalMap.end() ) {
            totalMap.insert(make_pair(b[i], 1));
        } else {
            Ait->second++;
        }
    }
    
    std::map<char, int> finalMap;
    
    for(std::map<char, int>::iterator itA = mapA.begin(); itA != mapA.end(); itA++) {
        for(std::map<char, int>::iterator itB = mapB.begin(); itB != mapB.end(); itB++) {
            if(itA->first == itB->first) {
                if(itA->second <= itB->second) {
                    finalMap.insert(make_pair(itA->first, itA->second));
                } else {
                    finalMap.insert(make_pair(itB->first, itB->second));
                }
            }
        }
    }
    
    int numberNeeded = 0;
    for(std::map<char, int>::iterator itF = finalMap.begin(); itF != finalMap.end(); itF++) {
        numberNeeded += itF->second;
    }
    
    int numberTotal = 0;
    for(std::map<char, int>::iterator itT = totalMap.begin(); itT != totalMap.end(); itT++) {
        numberTotal += itT->second;
    }
    
    int numberDeleted = numberTotal - (numberNeeded * 2);
    
    return numberDeleted;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
