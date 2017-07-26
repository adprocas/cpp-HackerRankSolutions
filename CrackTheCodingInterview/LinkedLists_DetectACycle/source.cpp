/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <map>

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head == NULL)
        return false;
    
    map<Node*, int> nodes;
    nodes.insert(make_pair(head, 1));
    int x = 1;
    
    while(head->next != NULL) {
        if(nodes.find(head->next) != nodes.end()) {
            return true;
        } else {
            nodes.insert(make_pair(head->next, 1));
        }
        
        head = head->next;
    }
    
    return false;
}
