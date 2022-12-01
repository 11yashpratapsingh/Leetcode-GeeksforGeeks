class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int p=0,ne=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[p] = nums[i];
                p += 2;
            }
            else{
                ans[ne] = nums[i];
                ne += 2;
            }
        }
        
        return ans;
    }
};