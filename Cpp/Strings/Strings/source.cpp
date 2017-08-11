#include <iostream>
#include <string>
using namespace std;

int main() {
   // Complete the program
    string s1;
    string s2;
    
    cin >> s1 >> s2;
    
    cout << s1.size() << " " << s2.size() << endl;
    
    cout << s1 + s2 << endl;
    
    cout << s2[0];
    for(int i = 1; i < s1.size(); ++i) {
        cout << s1[i];
    }
    
    cout << " ";
    
    cout << s1[0];
    for(int i = 1; i < s2.size(); ++i) {
        cout << s2[i];
    }
  
    return 0;
}