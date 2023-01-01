class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int,int> mp;
        
        int cnt = 0;
        for(int i=0;i<words.size();i++){
            int mask = 0;
            for(char ch: words[i]) mask |= 1 << (ch - 'a');
            
            cnt += mp[mask]++;
        }
        
        return cnt;
    }
};