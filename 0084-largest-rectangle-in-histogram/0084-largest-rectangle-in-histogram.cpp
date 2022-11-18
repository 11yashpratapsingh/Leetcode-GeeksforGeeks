class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int mxAns = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int height = arr[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                mxAns = max(mxAns, width*height);
            }
            st.push(i);
        }
        
        return mxAns;
    }
};