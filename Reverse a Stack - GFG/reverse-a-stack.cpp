//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void bottomInsert(stack<int> &st, int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }
        
        int tp = st.top();
        st.pop();
        bottomInsert(st,ele);
        st.push(tp);
    }

    void solve(stack<int> &st){
        if(st.empty()) return;
        
        int ele = st.top();
        st.pop();
        solve(st);
        
        bottomInsert(st,ele);
    }

    void Reverse(stack<int> &St){
        solve(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends