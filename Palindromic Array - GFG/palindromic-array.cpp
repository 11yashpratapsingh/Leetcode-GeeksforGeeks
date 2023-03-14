//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:

    bool palin(int num){
        string st = to_string(num);
        int i=0, j = st.length()-1;
        while(i<j){
            if(st[i] != st[j]) return false;
            i++, j--;
        }
        
        return true;
    }

    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0;i<n;i++){
    	    if(!palin(a[i])) return 0;
    	}
    	
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends