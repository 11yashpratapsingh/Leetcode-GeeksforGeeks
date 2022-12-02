class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        vector<int> mp1(26,0),mp2(26,0);
        for(int i=0;i<word1.size();i++){
            mp1[word1[i] - 'a']++;
            mp2[word2[i] - 'a']++;
        }
        
        for(int i=0;i<26;i++){
            if((mp1[i]>0 && mp2[i] == 0) || (mp1[i]==0 && mp2[i] > 0)) return false;
        }
        
        sort(mp1.begin(),mp1.end());
        sort(mp2.begin(),mp2.end());
        
        for(int i=0;i<mp1.size();i++){
            if(mp1[i]!=mp2[i]) return false;
        }
        
        return true;
    }
};