//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int func(vector<int>& mp){
      int mn =INT_MAX, mx = INT_MIN;
      for(int i=0;i<26;i++){
          if(mp[i] == 0) continue;
          mn = min(mn,mp[i]);
          mx= max(mx,mp[i]);
      }
      
      return mx-mn;
  }
  
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            vector<int> mp(26,0);
            for(int j=i;j<n;j++){
                mp[s[j] - 'a']++;
                ans += func(mp);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends