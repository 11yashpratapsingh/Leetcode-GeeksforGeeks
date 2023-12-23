class Solution {
public:
    
    int solve(vector<int>& days, vector<int>& costs, int n, int idx){
        if(idx >= n) return 0;
        
        int opt1 = costs[0] + solve(days,costs,n,idx+1);
        
        int i;
        for(i=idx;i<n && days[i]<days[idx]+7;i++);
        
        int opt2 = costs[1] + solve(days,costs,n,i);
        
        for(int i=idx;i<n && days[i]<days[idx]+30;i++);
        
        int opt3 = costs[2] + solve(days,costs,n,i);
        
        return min(opt1, min(opt2,opt3));
    }
    
    int solveMem(vector<int>& days, vector<int>& costs, int n, int idx, vector<int>& dp){
        if(idx >= n) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int opt1 = costs[0] + solveMem(days,costs,n,idx+1,dp);
        
        int i;
        for(i=idx;i<n && days[i]<days[idx]+7;i++);
        int opt2 = costs[1] + solveMem(days,costs,n,i,dp);
        
        for(int i=idx;i<n && days[i]<days[idx]+30;i++);
        int opt3 = costs[2] + solveMem(days,costs,n,i,dp);
        
        dp[idx] = min(opt1, min(opt2,opt3));
        
        return dp[idx];
    }
    
    int solveTab(vector<int>& days, vector<int>& costs, int n, int idx){
        
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;
        
        for(int k=n-1;k>=0;k--){
            int opt1 = costs[0] + dp[k+1];
        
            int i;
            for(i=k;i<n && days[i]<days[k]+7;i++);
            int opt2 = costs[1] + dp[i];

            for(i=k;i<n && days[i]<days[k]+30;i++);
            int opt3 = costs[2] + dp[i];

            dp[k] = min(opt1, min(opt2,opt3));
        }
        
        return dp[0];
    }
    
    int solveSpaceOpt(vector<int>& days, vector<int>& costs){
        int ans = 0;
        queue<pair<int,int>> month;
        queue<pair<int,int>> week;
        for(int day: days){
            while(!month.empty() && month.front().first + 30 <= day) month.pop();
            while(!week.empty() && week.front().first + 7 <= day) week.pop();
            
            week.push(make_pair(day,ans+costs[1]));
            month.push(make_pair(day,ans+costs[2]));
            
            ans = min(ans+costs[0], min(week.front().second, month.front().second));
        }
        
        return ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        //vector<int> dp(n+1, -1);
        //return solveMem(days,costs,n,0,dp);
        //return solveTab(days,costs,n,0);
        return solveSpaceOpt(days,costs);
    }
};