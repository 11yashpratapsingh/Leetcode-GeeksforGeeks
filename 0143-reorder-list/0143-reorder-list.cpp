/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* func(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr= head;
        ListNode* nxt=NULL;
        
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode* sl = head;
        ListNode* ft = head;
        while(ft && ft->next){
            sl = sl->next;
            ft = ft->next->next;
        }
        
        ListNode* second = func(sl->next);
        sl->next = NULL;
        ListNode* first = head;
        
        while(second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};