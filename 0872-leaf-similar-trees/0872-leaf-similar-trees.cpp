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
    
    void func(TreeNode* root, string &s){
        if(!root) return;
        if(root->left == NULL && root->right == NULL) s += root->val + 'a' + '#';
        func(root->left,s);
        func(root->right,s);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1,s2;
        func(root1,s1);
        func(root2,s2);
        return s1 == s2;
    }
};