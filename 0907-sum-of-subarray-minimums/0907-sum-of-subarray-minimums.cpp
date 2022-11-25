class Solution {
public:
    
    int mod = 1e9+7;
    
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int lt[n];
        int rt[n];
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) lt[i] = i+1;
            else lt[i]=i-st.top();
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
       
        //right part
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) rt[i] = n-i;
            else rt[i]=st.top()-i;
            st.push(i);
        }
        
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            long long prod = (lt[i]*rt[i])%mod;
            maxA = (maxA + (prod*arr[i])%mod)%mod;
        }
        return maxA;
    }
};