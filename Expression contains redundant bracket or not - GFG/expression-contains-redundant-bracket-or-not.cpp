//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<int> st;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') st.push(ch);
            else{
                if(ch == ')'){
                    bool isRedundant = true;
                    
                    while(st.top() != '('){
                        char tp = st.top();
                        if(tp == '+' || tp == '-' || tp == '*' || tp == '/') isRedundant = false;
                        st.pop();
                    }
                    
                    if(isRedundant) return 1;
                    st.pop();
                }
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends