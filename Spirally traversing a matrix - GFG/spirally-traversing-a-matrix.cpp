//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
    {
        // code here 
        int rwSt = 0, rwEd = r-1, clSt = 0, clEd = c-1;
        vector<int> ans;
        while(rwSt<=rwEd && clSt<=clEd){
            for(int i=clSt;i<=clEd;i++) ans.push_back(a[rwSt][i]);
            rwSt++;
            for(int i=rwSt;i<=rwEd;i++) ans.push_back(a[i][clEd]);
            clEd--;
            if(rwSt<=rwEd){
                for(int i=clEd;i>=clSt;i--) ans.push_back(a[rwEd][i]);
                rwEd--;
            }
            if(clSt<=clEd){
                for(int i=rwEd;i>=rwSt;i--) ans.push_back(a[i][clSt]);
                clSt++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends