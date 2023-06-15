class Solution {
public:
    
    void func(vector<int>& nums, vector<vector<int>>& ans, vector<int> tmp, int idx){
        ans.push_back(tmp);
        
        for(int i=idx;i<nums.size();i++){
            tmp.push_back(nums[i]);
            func(nums,ans,tmp,i+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int idx = 0;
        func(nums,ans,tmp,idx);
        return ans;
    }
};