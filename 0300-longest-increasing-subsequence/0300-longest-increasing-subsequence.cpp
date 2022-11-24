class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int len = 1;
	    vector<int> dp1(n,1);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i] && 1+dp1[j]>dp1[i]) dp1[i] = 1+dp1[j]; 
	        }
            len = max(len,dp1[i]);
	    }
        return len;
    }
};