class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> job(n, vector<int>(3));
        map<int,int> mp;            // startTime, profit
        for(int i=0;i<n;i++){
            job[i] = {startTime[i],endTime[i],profit[i]};
        }
        
        sort(job.begin(),job.end());
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            int curr = job[i][2];
            auto it = mp.lower_bound(job[i][1]);
            if(it != mp.end()) curr += it->second;
            ans = max(ans,curr);
            mp[job[i][0]] = ans;
        }
        return ans;
    }
};