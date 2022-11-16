class Solution
{
    public:
    
    int func(vector<int>& mp){
        int mn = INT_MAX, mx= INT_MIN;
        for(int i=0;i<26;i++){
            if(mp[i] == 0) continue;
            mn = min(mn,mp[i]);
            mx = max(mx,mp[i]);
        }
        
        return mx-mn;
    }
    
        int beautySum(string s) {
            int ans = 0;
            int n = s.length();
            for(int i=0;i<n;i++){
                vector<int> mp(26,0);
                for(int j=i;j<n;j++){
                    mp[s[j] - 'a']++;
                    ans += func(mp);
                }
            }
            return ans;
        }
};