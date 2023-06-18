//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void func(int i, int j, vector<string>& ans, vector<vector<int>>& vis, vector<vector<int>> &m, int di[], int dj[], int n, string move){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }
        
        string patt = "DLRU";
        for(int x=0;x<4;x++){
            int nxti = i + di[x];
            int nxtj = j + dj[x];
            if(nxti>=0 && nxtj>=0 && nxti<n && nxtj<n && !vis[nxti][nxtj] && m[nxti][nxtj] == 1){
                vis[i][j] = 1;
                func(nxti,nxtj,ans,vis,m,di,dj,n,move+patt[x]);
                vis[i][j] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};
        string move = "";
        if(m[0][0] == 1) func(0,0,ans,vis,m,di,dj,n,move);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends