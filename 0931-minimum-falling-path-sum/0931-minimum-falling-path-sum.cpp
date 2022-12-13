class Solution {
public:
    
    int func(int i, int j, int m, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(j<0 || j>=m) return 1e9;
        if(i==0) return mat[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = mat[i][j] + func(i-1,j,m,mat,dp);
        int lt = mat[i][j] + func(i-1,j-1,m,mat,dp);
        int rt = mat[i][j] + func(i-1,j+1,m,mat,dp);
        
        return dp[i][j] = min(up,min(lt,rt));
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        int ans = INT_MAX;
        for(int j=0;j<m;j++){
            int num = func(n-1,j,m,mat,dp);
            ans = min(ans,num);
        }
        
        return ans;
    }
};