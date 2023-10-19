class Solution {
public:
    
    int solve(vector<int>& cost, int n, vector<int>& v){
        if(n == 0 || n == 1) return cost[n];
        
        if(v[n] != -1) return v[n];
        
        v[n] = cost[n] + min(solve(cost,n-1,v), solve(cost,n-2,v));
        return v[n];
    }
    
    int solve2(vector<int>& cost, int n){
        //vector<int> dp(n+1);
        
        //dp[0] = cost[0];
        //dp[1] = cost[1];
        int var1 = cost[0];
        int var2 = cost[1];
        for(int i=2;i<n;i++){
            //dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
            int var = cost[i] + min(var1,var2);
            var1 = var2;
            var2 = var;
        }
                                  
        return min(var1,var2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //vector<int> v(n+1,-1);
        //int ans = min(solve(cost,n-1,v),solve(cost,n-2,v));
        return solve2(cost,n);
    }
};