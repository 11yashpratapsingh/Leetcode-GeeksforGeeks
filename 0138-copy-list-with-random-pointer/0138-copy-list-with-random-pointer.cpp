/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp = head;
        while(tmp){
            Node* nw = new Node(tmp->val);
            nw->next = tmp->next;
            tmp->next = nw;
            tmp = nw->next;
        }
        
        tmp = head;
        while(tmp){
            if(tmp->random){
                tmp->next->random = tmp->random->next;
            }
            
            tmp = tmp->next->next;
        }
        
        Node* dummy = new Node(-1);
        tmp = dummy;
        Node* itr = head;
        Node* fast;
        while(itr){
            fast = itr->next->next;
            tmp->next = itr->next;
            itr->next = fast;
            tmp = tmp->next;
            itr = fast;
        }
        
        return dummy->next;
    }
};