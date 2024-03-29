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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr = head;
        while(curr){
            if(curr->next != NULL && curr->val == curr->next->val){
                ListNode* del = curr->next;
                curr->next = curr->next->next;
                delete(del);
            }
            else{
                curr = curr->next;
            }
        }
        
        //prev->next = NULL;
        return head;
    }
};