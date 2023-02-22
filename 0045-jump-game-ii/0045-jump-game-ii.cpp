class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, maxi = 0, steps = 0;
        for(int i=0;i<nums.size()-1;i++){
            maxi = max(maxi, i+nums[i]);
            if(i == steps){
                jumps++;
                steps = maxi;
            }
        }
        
        return jumps;
    }
};