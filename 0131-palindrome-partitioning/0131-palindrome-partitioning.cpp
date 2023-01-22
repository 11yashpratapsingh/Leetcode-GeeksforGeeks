class Solution {
public:
    bool isPalindrome(string s,int st, int en){
        while(st<=en){
            if(s[st]!=s[en]) return false;
            st++, en--;
        }
        
        return true;
    }
    
    void func(int ind, vector<string>& ds, vector<vector<string>>& ans, string s){
        if(ind == s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                func(i+1,ds,ans,s);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        func(0,ds,ans,s);
        return ans;
    }
};