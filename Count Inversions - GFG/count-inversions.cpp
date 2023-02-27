//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long arr[], long long st, long long mid, long long ed, long long temp[]){
        long long i=st, j = mid, k = st;
        long long cnt = 0;
        while(i<=mid-1 && j<=ed){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                cnt += (mid-i);
            }
        }
        
        while(i<=mid-1) temp[k++] = arr[i++];
        while(j<=ed) temp[k++] = arr[j++];
        
        for(int i=st;i<=ed;i++) arr[i] = temp[i];
        
        return cnt;
    }
    
    long long int mergeSort(long long arr[], long long st, long long ed, long long temp[]){
        long long int mid,cnt = 0;
        if(st<ed){
            mid = (st+ed)/2;
            
            cnt += mergeSort(arr,st,mid,temp);
            cnt += mergeSort(arr,mid+1,ed,temp);
            
            cnt += merge(arr,st,mid+1,ed,temp);
        }
        
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergeSort(arr,0,N-1,temp);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends