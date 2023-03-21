//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int R, int C) 
    {
        // code here 
        
        vector<int> ans;
        int rowStart = 0, rowEnd = R-1, colStart = 0, colEnd = C-1;
        while(rowStart<=rowEnd && colStart<=colEnd){
            for(int i=colStart;i<=colEnd;i++) ans.push_back(a[rowStart][i]);
            rowStart++;
            for(int i=rowStart;i<=rowEnd;i++) ans.push_back(a[i][colEnd]);
            colEnd--;
            if(rowStart<=rowEnd){
                for(int i=colEnd;i>=colStart;i--) ans.push_back(a[rowEnd][i]);
                rowEnd--;
            }
            if(colStart<=colEnd){
                for(int i=rowEnd;i>=rowStart;i--) ans.push_back(a[i][colStart]);
                colStart++;
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