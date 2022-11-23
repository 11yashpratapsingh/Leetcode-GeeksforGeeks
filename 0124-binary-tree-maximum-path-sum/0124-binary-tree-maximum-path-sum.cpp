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
    
    int func(TreeNode* root, int& ans){
        if(!root) return 0;
        
        int lt = max(0, func(root->left,ans));
        int rt = max(0,func(root->right,ans));
        
        ans = max(ans,lt+rt+root->val);
        return max(lt,rt)+ root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        func(root,ans);
        return ans;
    }
};