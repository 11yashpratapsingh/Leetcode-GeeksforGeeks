//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  bool func(int arr[], int mid, int n ,int k){
      int cnt = 1;
      int sm = 0;
      
      for(int i=0;i<n;i++){
          if(sm + arr[i] > mid){
              cnt++;
              sm = arr[i];
          }
          else sm += arr[i];
      }
      
      return cnt<=k;
  }
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long sm = 0;
        int ans=-1;
        for(int i=0;i<n;i++){
            sm += arr[i];
            ans = max(ans,arr[i]);
        }
        
        long long lw = ans, hg = sm;
        while(lw<=hg){
            int mid = lw + (hg-lw)/2;
            if(func(arr,mid,n,k)){
                ans = mid;
                hg= mid-1;
            }
            else lw = mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends