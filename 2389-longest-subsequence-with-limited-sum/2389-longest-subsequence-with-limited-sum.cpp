class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        int sm = 0;
        for(int i=0;i<nums.size();i++){
            sm += nums[i];
            tmp.push_back(sm);
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(upper_bound(tmp.begin(),tmp.end(),queries[i]) - tmp.begin());
        }
        
        return ans;
    }
};