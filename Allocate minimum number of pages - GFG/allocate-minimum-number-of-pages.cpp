//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool func(int rng, int n, int m, int a[]){
        int sm = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(sm + a[i] > rng){
                cnt++;
                sm = a[i];
                if(sm > rng) return false;
            }
            else{
                sm += a[i];
            }
        }
        
        if(cnt < m) return true;
        return false;
    }
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(m>n) return -1; 
        int ans = -1;
        int sm = 0;
        for(int i=0;i<n;i++) sm += a[i];
        
        int lw=a[0], hg = sm;
        while(lw<=hg){
            int mid = lw + (hg-lw)/2;
            if(func(mid,n,m,a)) hg = mid-1;
            else lw = mid+1;
        }
        
        return lw;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends