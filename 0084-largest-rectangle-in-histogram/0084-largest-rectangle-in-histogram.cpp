class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int lt[n];
        int rt[n];
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) lt[i] = 0;
            else lt[i]=st.top()+1;
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
            if(st.empty()) rt[i] = n-1;
            else rt[i]=st.top()-1;
            st.push(i);
        }
        
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, arr[i] * (rt[i] - lt[i] + 1));
        }
        return maxA;
    }
};