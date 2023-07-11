/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentNode, TreeNode* tar){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left){
                parentNode[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right){
                parentNode[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentNode;
        findParent(root,parentNode,target);
        
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int currLevel = 0;
        while(!q.empty()){
            int sz = q.size();
            if(currLevel++ == k) break;
            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                
                if(parentNode[curr] && !vis[parentNode[curr]]){
                    q.push(parentNode[curr]);
                    vis[parentNode[curr]] = true;
                }
            }
        }
        
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};