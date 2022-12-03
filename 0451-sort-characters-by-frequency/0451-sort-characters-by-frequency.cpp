class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto it: mp) pq.push({it.second,it.first});
        
        string ans = "";
        while(!pq.empty()){
            auto tmp = pq.top();
            pq.pop();
            while(tmp.first--) ans += tmp.second;
        }
        
        return ans;
    }
};