class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == num1) cnt1++;
            else if(nums[i] == num2) cnt2++;
            else if(cnt1 == 0) num1 = nums[i], cnt1++;
            else if(cnt2 == 0) num2 = nums[i], cnt2++;
            else cnt1--, cnt2--;
        }
        
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == num1) cnt1++;
            else if(nums[i] == num2) cnt2++;
        }
        
        if(cnt1> n/3) ans.push_back(num1);
        if(cnt2 > n/3) ans.push_back(num2);
        
        return ans;
    }
};