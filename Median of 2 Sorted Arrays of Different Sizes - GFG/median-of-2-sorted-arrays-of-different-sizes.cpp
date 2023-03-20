//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Your code goes here
        int m = nums1.size(), n = nums2.size();
        if(m>n) return MedianOfArrays(nums2,nums1);
        
        int low = 0, high = m, medianPos = (m+n+1)/2;
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = medianPos - cut1;
            
            int l1 = (cut1==0) ? INT_MIN:nums1[cut1-1];
            int l2 = (cut2==0) ? INT_MIN:nums2[cut2-1];
            int r1 = (cut1==m) ? INT_MAX:nums1[cut1];
            int r2 = (cut2==n) ? INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                if((m+n)%2 != 0) return max(l1,l2);
                else return (max(l1,l2) + min(r1,r2))/2.0;
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1+1;
        }
        return 0.0;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends