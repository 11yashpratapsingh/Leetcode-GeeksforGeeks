//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> pre(n,0), suf(n,0);
        
        pre[0] = arr[0];
        for(int i=1;i<n;i++){
            pre[i] = max(pre[i-1],arr[i]);
        }
        
        suf[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = max(suf[i+1],arr[i]);
        }
        
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += min(pre[i],suf[i]) - arr[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends