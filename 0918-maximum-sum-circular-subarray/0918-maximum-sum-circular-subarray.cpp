class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tot=0, mxSum = 0, mx = nums[0], mn = nums[0], mnSum = 0;
        for(int i=0;i<nums.size();i++){
            tot += nums[i];
            mxSum = max(nums[i],mxSum+nums[i]);
            mx = max(mx,mxSum);
            mnSum = min(nums[i],mnSum+nums[i]);
            mn = min(mn,mnSum);
        }
        
        return mx>0? max(mx,tot-mn) : mx;
    }
};