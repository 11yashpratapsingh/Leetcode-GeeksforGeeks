//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int solve(int *arr, int n, vector<int> &v){
        if(n<0) return 0;
        if(n == 0) return arr[0];
        
        if(v[n] != -1) return v[n];
        
        int incl = arr[n] + solve(arr,n-2,v);
        int excl = 0 + solve(arr,n-1,v);
        
        v[n] = max(incl,excl);
        return v[n];
    }
    
    

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    //vector<int> v(n,0);
	    //return solve(arr,n-1,v);
	    
	    //v[0] = arr[0];
	    int prev2 = 0;
	    int prev1 = arr[0];
	    for(int i=1;i<n;i++){
	        int incl = arr[i] + prev2;
            int excl = 0 + prev1;
            prev2 = prev1;
            prev1 = max(incl,excl);
	    }
	    
	    return prev1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends