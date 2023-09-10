/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int cnt = 0;
    void func(TreeNode* root, long long targetSum){
        if(!root) return;
            
        if(root->val == targetSum) cnt++;
        
        func(root->left,targetSum-root->val);
        func(root->right,targetSum-root->val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            func(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        
        return cnt;
    }
};