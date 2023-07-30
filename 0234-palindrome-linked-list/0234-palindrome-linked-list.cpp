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
    
    ListNode* reverseNode(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* sl = head;
        ListNode* ft = head;
        while(ft->next && ft->next->next){
            sl = sl->next;
            ft = ft->next->next;
        }
        
        sl->next = reverseNode(sl->next);
        sl = sl->next;
    
        while(sl){
            if(head->val != sl->val) return false;
            sl = sl->next;
            head = head->next;
        }
        
        return true;
    }
};