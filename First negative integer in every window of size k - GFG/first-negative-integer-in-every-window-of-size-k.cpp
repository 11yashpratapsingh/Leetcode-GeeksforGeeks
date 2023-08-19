//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
    queue<long long> q;
    vector<long long> ans;
    for(int i=0;i<k;i++){
        if(arr[i]<0) q.push(i);
    }
    
    if(q.empty()) ans.push_back(0);
    else ans.push_back(arr[q.front()]);
    
    for(int i=k;i<n;i++){
        if(!q.empty() && i - q.front() >=k) q.pop();
        
        if(arr[i] < 0) q.push(i);
        
        if(q.size()>0) ans.push_back(arr[q.front()]);
        else ans.push_back(0);
    }
    return ans;
 }