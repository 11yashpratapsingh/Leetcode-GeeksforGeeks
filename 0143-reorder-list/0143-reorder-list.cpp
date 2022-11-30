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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* tmp = head;
        while(tmp){
            v.push_back(tmp);
            tmp = tmp->next;
        }
        
        int l = 1, r= v.size()-1;
        for(int i=0;i<v.size();i++){
            if(i&1) head->next = v[l++];
            else head->next = v[r--];
            head = head->next;
        }
        head->next = NULL;
    }
};