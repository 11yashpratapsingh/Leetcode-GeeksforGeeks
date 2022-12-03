//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool func(vector<int>& v, int n, int k, int mid){
        int cnt = 1;
        int dist = v[0];
        for(int i=1;i<n;i++){
            if(v[i]-dist >= mid){
                cnt++;
                dist = v[i];
            }
        }
        return cnt>=k;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int lw = 1, hg = stalls[n-1] - stalls[0];
        while(lw<=hg){
            int mid = lw + (hg-lw)/2;
            if(func(stalls,n,k,mid)){
                lw = mid+1;
            }
            else hg = mid-1;
        }
        
        return hg;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends