//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> count (string s)
        {
            //code here.
            int lc=0, uc=0, sc=0, nv=0;
            for(int i=0;i<s.length();i++){
                if(s[i]>= 'a' && s[i]<='z') lc++;
                else if(s[i]>= 'A' && s[i]<='Z') uc++;
                else if(s[i]>= '0' && s[i]<='9') nv++;
                else sc++;
            }
            
            return {uc,lc,nv,sc};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        vector <int> res = ob.count (s);
        for (int i : res)
            cout << i << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends