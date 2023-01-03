class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        for(int i=0;i<strs[0].length();i++){
            char st = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(st > strs[j][i]){
                    cnt++;
                    break;
                }
                st = strs[j][i];
            }
        }
        return cnt;
    }
};