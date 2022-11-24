class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int len = 1;
        vector<int> tmp;
        tmp.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(arr[i]>tmp.back()){
                len++;
                tmp.push_back(arr[i]);
            }
            else{
                int idx = lower_bound(tmp.begin(),tmp.end(), arr[i]) - tmp.begin();
                tmp[idx] = arr[i];
            }
        }
        return len;
    }
};