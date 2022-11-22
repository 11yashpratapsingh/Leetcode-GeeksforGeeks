class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            dp[i] = i;
            for(int j=1;j*j<=i;j++){
                int sq = j*j;
                dp[i] = min(dp[i],dp[i-sq]+1);
            }
        }
        
        return dp[n];
    }
};