#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
public:
    stack<int> stack_newest_on_top, stack_oldest_on_top;

    void push(int x) {
		//add to the storage stack - oldest will be at 'index' 0
        stack_oldest_on_top.push(x);
    }

    void pop() {
		//if we're out of older items, rebuild
		//essentially we're just reversing the 
		//oldest on top stack every time we're 
		//out of newest on top items
		//this lets us go through the stack
		//as if we are traversing backwards
        if(stack_newest_on_top.empty()) {
            buildStack();
        }
        
        stack_newest_on_top.pop();
    }

    int front() {
		//see above comment in pop - we want to
		//make sure that both situations produce
		//expected results, so we're doing the same
		//check for an empty newest on top stack
		//here too
        if(stack_newest_on_top.empty()) {
            buildStack();
        }
        
        return stack_newest_on_top.top();
    }
    
    void buildStack() {
        while(!stack_oldest_on_top.empty()) {
            stack_newest_on_top.push(stack_oldest_on_top.top());
            stack_oldest_on_top.pop();
        }
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
