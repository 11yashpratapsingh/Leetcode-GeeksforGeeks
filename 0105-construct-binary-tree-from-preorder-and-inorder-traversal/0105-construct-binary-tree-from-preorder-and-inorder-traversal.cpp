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
    
    TreeNode* func(vector<int>& preorder, int preSt, int preEd, vector<int>& inorder, int inSt, int inEd, map<int,int>& mp){
        if(preSt>preEd || inSt>inEd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preSt]);
        int ele = mp[root->val];
        int nEle = ele-inSt;
        
        root->left = func(preorder,preSt+1,preSt+nEle,inorder,inSt,ele-1,mp);
        root->right = func(preorder,preSt+nEle+1,preEd,inorder,ele+1,inEd,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        return func(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};