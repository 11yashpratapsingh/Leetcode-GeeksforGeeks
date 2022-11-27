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
    
    TreeNode* func(vector<int>& preorder, int& lwLimit, int hgLimit){
        if(lwLimit == preorder.size() || preorder[lwLimit]>hgLimit) return NULL;
        
        TreeNode* root = new TreeNode(preorder[lwLimit++]);
        root->left = func(preorder,lwLimit,root->val);
        root->right = func(preorder,lwLimit,hgLimit);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return func(preorder,i,INT_MAX);
    }
};