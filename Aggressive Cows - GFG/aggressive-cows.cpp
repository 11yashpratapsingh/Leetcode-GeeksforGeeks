//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  
  bool func(vector<int> &arr, int mid, int n ,int k){
      int cnt = 1;
      int sm = arr[0];
      
      for(int i=0;i<n;i++){
          if(arr[i] - sm >= mid){
              cnt++;
              if(cnt == k) return true;
              sm = arr[i];
          }
      }
      
      return false;
  }
  
    int solve(int n, int k, vector<int> &arr) {
    
        // Write your code here
        sort(arr.begin(),arr.end());
        int sm = -1;
        int ans=-1;
        for(int i=0;i<n;i++){
            sm = max(sm,arr[i]);
        }
        
        int lw = 0, hg = sm;
        while(lw<=hg){
            int mid = lw + (hg-lw)/2;
            if(func(arr,mid,n,k)){
                ans = mid;
                lw = mid+1;
            }
            else hg = mid-1;
        }
        
        return ans;
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