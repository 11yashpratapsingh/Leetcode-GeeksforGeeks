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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool lToR = true;
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp(sz);
            for(int i=0;i<sz;i++){
                TreeNode* tmp = q.front();
                q.pop();
                int idx = lToR? i : sz-1-i;
                temp[idx] = tmp->val;
                
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            
            res.push_back(temp);
            lToR = !lToR;
        }
        return res;
    }
};