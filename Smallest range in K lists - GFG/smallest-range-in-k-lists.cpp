//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range

class node{
    public:
    int data;
    int row;
    int col;
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int nums[][N], int n, int k)
    {
          //code here
        priority_queue<node*,vector<node*>, compare> q;
        
        int mn = INT_MAX, mx = INT_MIN;
        
        for(int i=0;i<k;i++){
            q.push(new node(nums[i][0],i,0));
            mn = min(mn,nums[i][0]);
            mx = max(mx,nums[i][0]);
        }
        
        int st = mn , ed = mx;
        while(!q.empty()){
            node* tmp = q.top();
            q.pop();
            
            mn = tmp->data;
            
            if(mx - mn < ed - st){
                st = mn;
                ed = mx;
            }
            
            if(tmp->col + 1 < n){
                mx = max(mx,nums[tmp->row][tmp->col + 1]);
                q.push(new node(nums[tmp->row][tmp->col + 1],tmp->row,tmp->col + 1));
            }
            else break;
        }
        
        return {st,ed};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends