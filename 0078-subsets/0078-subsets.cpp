class Solution {
public:
    
    void func(vector<int>& nums, vector<vector<int>>& ans, vector<int> tmp, int idx){
        if(idx>= nums.size()){
            ans.push_back(tmp);
            return;
        }
        
        tmp.push_back(nums[idx]);
        func(nums,ans,tmp,idx+1);
        tmp.pop_back();
        func(nums,ans,tmp,idx+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int idx = 0;
        func(nums,ans,tmp,idx);
        return ans;
    }
};