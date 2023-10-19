class Solution {
public:
    
    int solve(vector<int>& cost, int n, vector<int>& v){
        if(n == 0 || n == 1) return cost[n];
        
        if(v[n] != -1) return v[n];
        
        v[n] = cost[n] + min(solve(cost,n-1,v), solve(cost,n-2,v));
        return v[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> v(n+1,-1);
        int ans = min(solve(cost,n-1,v),solve(cost,n-2,v));
        return ans;
    }
};