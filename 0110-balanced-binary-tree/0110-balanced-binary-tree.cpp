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
    
    int func(TreeNode* root){
        if(!root) return NULL;
        
        int lt = func(root->left);
        if(lt == -1) return -1;
        
        int rt = func(root->right);
        if(rt == -1) return -1;
        
        if(abs(lt-rt) > 1) return -1;
        
        return max(lt,rt) +1;
    }
    
    bool isBalanced(TreeNode* root) {
        return func(root) != -1;
    }
};