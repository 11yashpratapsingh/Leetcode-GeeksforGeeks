class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        vector<vector<int>> ans(2);
        for(int i=0;i<matches.size();i++){
            if(!mp.count(matches[i][0])) mp[matches[i][0]] = 0;
            mp[matches[i][1]]++;
        }
        
        for(auto it: mp){
            if(it.second == 0) ans[0].push_back(it.first);
            else if(it.second == 1) ans[1].push_back(it.first);
        }
        return ans;
    }
};