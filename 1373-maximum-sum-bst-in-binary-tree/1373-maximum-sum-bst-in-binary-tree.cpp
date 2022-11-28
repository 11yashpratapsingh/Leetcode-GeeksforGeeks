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

class NodeValue{
    public:
    int mx,mn,mxSum;
    
    NodeValue(int mn, int mx, int mxSum){
        this->mx = mx;
        this->mn = mn;
        this->mxSum = mxSum;
    }
};

class Solution {
public:
    
    int sm = 0;
    
    NodeValue func(TreeNode* root){
        if(!root) return {INT_MAX,INT_MIN,0};
        
        auto lt = func(root->left);
        auto rt = func(root->right);
        
        if(lt.mx < root->val && root->val < rt.mn){
            sm = max(sm,lt.mxSum+rt.mxSum+root->val);
            return NodeValue(min(root->val,lt.mn), max(root->val,rt.mx), lt.mxSum+rt.mxSum+root->val);
        }
        
        return NodeValue(INT_MIN,INT_MAX,max(lt.mxSum, rt.mxSum));
    }
    
    int maxSumBST(TreeNode* root) {
        func(root);
        return sm>0?sm:0;
    }
};