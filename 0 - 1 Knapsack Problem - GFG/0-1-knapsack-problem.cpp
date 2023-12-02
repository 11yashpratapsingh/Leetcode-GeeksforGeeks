//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int w, int n, int wt[], int val[]){
        if(n == 0){
            if(wt[n]<=w) return val[n];
            return 0;
        }
        
        int notTake = 0 + solve(w,n-1,wt,val);
        int take = INT_MIN;
        if(wt[n]<=w) take = val[n] + solve(w-val[n],n-1,wt,val);
        
        return max(notTake,take);
    }
    
    int solveMem(int w, int n, int wt[], int val[], vector<vector<int>> &dp){
        if(n == 0){
            if(wt[n]<=w) return val[n];
            return 0;
        }
        
        if(dp[n][w] != -1) return dp[n][w];
        
        int notTake = 0 + solveMem(w,n-1,wt,val,dp);
        int take = INT_MIN;
        if(wt[n]<=w) take = val[n] + solveMem(w-val[n],n-1,wt,val,dp);
        
        dp[n][w] = max(notTake,take);
        return dp[n][w];
    }
    
    int solveTab(int w, int n, int wt[], int val[]){
        vector<vector<int>> dp(n, vector<int> (w+1,0));
        
        for(int i=wt[0];i<=w;i++) dp[0][i] = val[0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int notTake = 0 + dp[i-1][j];
                int take = INT_MIN;
                if(wt[i]<=j) take = val[i] + dp[i-1][j-wt[i]];
                
                dp[i][j] = max(notTake,take);
            }
        }
        return dp[n-1][w];
    }
    
    int spaceOpt(int w, int n, int wt[], int val[]){
        vector<int> prev(w+1,0), curr(w+1);
        
        for(int i=wt[0];i<=w;i++) prev[i] = val[0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int notTake = 0 + prev[j];
                int take = INT_MIN;
                if(wt[i]<=j) take = val[i] + prev[j-wt[i]];
                
                curr[j] = max(notTake,take);
            }
            prev = curr;
        }
        return prev[w];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       //vector<vector<int>> dp(n, vector<int> (W+1,-1));
       return solveTab(W,n, wt, val);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends