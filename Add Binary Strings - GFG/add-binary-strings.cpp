//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    string ans = "";
	    int n = A.length();
	    int m = B.length();
	    int i=n-1,j=m-1,carry = 0;
	    
	    while(i>=0 || j>=0 || carry){
	        int sm = 0;
	        if(i>=0){
	            sm += A[i] - '0';
	            i--;
	        }
	        if(j>=0){
	            sm += B[j] - '0';
	            j--;
	        }
	        
	        sm += carry;
	        carry = sm/2;
	        ans += sm%2 + '0';
	    }
	    
	    reverse(ans.begin(),ans.end());
	    i=0;
	    while(ans[i] == '0') i++;
	    
	    ans.erase(0,i);
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends