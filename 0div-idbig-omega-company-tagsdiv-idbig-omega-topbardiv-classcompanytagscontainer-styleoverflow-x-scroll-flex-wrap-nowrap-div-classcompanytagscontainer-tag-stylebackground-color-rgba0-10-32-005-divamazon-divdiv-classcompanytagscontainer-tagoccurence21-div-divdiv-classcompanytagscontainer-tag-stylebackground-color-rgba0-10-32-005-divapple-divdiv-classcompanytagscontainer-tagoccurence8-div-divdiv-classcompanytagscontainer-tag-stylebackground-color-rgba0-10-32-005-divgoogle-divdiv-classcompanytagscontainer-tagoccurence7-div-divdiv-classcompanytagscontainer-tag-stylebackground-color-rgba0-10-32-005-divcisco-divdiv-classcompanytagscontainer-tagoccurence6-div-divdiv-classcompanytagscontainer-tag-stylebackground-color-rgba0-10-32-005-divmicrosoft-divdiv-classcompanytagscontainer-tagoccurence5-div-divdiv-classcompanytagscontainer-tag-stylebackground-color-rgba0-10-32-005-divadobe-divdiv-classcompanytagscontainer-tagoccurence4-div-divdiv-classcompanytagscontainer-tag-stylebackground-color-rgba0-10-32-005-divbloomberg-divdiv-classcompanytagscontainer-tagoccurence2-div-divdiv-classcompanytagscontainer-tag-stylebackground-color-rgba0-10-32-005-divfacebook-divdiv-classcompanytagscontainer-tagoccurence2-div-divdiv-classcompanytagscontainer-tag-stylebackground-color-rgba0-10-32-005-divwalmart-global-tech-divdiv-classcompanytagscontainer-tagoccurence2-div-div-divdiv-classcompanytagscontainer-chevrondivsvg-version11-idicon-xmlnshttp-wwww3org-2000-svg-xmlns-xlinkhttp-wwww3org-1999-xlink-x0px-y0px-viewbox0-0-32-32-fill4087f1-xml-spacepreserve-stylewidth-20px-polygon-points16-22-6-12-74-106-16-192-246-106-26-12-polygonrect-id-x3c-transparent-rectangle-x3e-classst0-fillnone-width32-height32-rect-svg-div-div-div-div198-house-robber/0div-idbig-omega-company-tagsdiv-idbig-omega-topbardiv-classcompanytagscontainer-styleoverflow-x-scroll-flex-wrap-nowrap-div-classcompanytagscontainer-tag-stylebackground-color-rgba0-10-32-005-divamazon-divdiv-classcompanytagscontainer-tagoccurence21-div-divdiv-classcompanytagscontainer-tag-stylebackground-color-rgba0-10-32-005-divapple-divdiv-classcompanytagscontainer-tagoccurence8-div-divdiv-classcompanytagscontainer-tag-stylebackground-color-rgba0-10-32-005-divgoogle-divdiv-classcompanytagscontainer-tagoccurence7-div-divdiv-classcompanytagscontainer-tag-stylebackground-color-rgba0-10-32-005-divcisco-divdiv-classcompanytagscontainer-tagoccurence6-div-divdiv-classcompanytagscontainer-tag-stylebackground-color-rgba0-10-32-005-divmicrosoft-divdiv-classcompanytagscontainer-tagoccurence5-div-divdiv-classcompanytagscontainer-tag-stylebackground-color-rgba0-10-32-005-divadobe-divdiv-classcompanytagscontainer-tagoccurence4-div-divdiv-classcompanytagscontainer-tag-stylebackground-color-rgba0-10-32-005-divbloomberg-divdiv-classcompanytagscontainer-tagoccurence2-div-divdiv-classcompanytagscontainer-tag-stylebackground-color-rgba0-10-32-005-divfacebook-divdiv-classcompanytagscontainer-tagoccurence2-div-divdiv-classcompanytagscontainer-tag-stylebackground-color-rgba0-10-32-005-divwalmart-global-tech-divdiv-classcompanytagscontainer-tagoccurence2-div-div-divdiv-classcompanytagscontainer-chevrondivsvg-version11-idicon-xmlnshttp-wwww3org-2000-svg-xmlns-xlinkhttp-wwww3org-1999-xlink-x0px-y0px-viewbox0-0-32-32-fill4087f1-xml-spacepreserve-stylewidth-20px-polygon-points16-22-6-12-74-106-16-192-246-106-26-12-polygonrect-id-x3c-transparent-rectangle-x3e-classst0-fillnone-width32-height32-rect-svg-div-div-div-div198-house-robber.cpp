class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        int prev2 = 0;
	    int prev1 = arr[0];
	    for(int i=1;i<n;i++){
	        int incl = arr[i] + prev2;
            int excl = 0 + prev1;
            prev2 = prev1;
            prev1 = max(incl,excl);
	    }
	    
	    return prev1;
    }
};