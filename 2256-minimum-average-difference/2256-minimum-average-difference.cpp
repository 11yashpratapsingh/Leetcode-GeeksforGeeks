class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long totSum = 0;
        for(int i=0;i<n;i++){
            totSum += nums[i];
        }
        
        long curSum = 0;
        int val = INT_MAX;
        int idx = 0;
        for(int i=0;i<n;i++){
            curSum += nums[i];
            int avg1 = curSum/(i+1);
            if(i==n-1){
                if(avg1<val) return n-1;
                else break;
            }
            
            int avg2 = (totSum - curSum)/(n-i-1);
            if(abs(avg1-avg2)<val){
                val = abs(avg1-avg2);
                idx = i;
            }
        }
        return idx;
    }
};