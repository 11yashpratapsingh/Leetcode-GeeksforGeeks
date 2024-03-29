//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        long long ans = 0;
        int l = 0, r = n-1;
        int ltMx = 0, rtMx = 0;
        
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(ltMx<=arr[l]) ltMx = arr[l];
                else ans += ltMx - arr[l];
                
                l++;
            }
            else{
                if(rtMx<=arr[r]) rtMx = arr[r];
                else ans += rtMx-arr[r];
                r--;
            }
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