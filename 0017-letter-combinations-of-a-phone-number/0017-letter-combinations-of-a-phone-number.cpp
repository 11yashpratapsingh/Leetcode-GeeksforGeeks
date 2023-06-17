class Solution {
public:
    unordered_map<char, string> L = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    
    void func(int i, string digits, string tmp, vector<string>& ans){
        if(tmp.length() == digits.length()) ans.push_back(tmp);
        
        string lett = L[digits[i]];
        for(int j=0;j<lett.length();j++){
            tmp += lett[j];
            func(i+1,digits,tmp,ans);
            tmp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> ans;
        if(!n) return ans;
        string tmp = "";
        func(0,digits,tmp,ans);
        return ans;
    }
};