class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long totSum = 0, currSum = 0;
        for(int i=0;i<n;i++) totSum += nums[i];
        
        int idx = 0;
        int val = INT_MAX;
        
        for(int i=0;i<n;i++){
            currSum += nums[i];
            int avg1 = currSum/(i+1);
            if(i==n-1){
                if(avg1<val) return n-1;
                else break;
            }
            
            int avg2 = (totSum - currSum)/(n-i-1);
            if(abs(avg2-avg1)<val){
                val = abs(avg2-avg1);
                idx = i;
            }
        }
        return idx;
    }
};