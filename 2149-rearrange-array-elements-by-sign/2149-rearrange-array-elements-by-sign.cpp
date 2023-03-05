class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
	    int p=0,ne=1;
	    for(int i=0;i<n;i++){
	        if(arr[i]>0){
	            ans[p] = arr[i];
	            p+=2;
	        }
	        else{
	            ans[ne] = arr[i];
	            ne+=2;
	        }
	    }
        
        return ans;
    }
};