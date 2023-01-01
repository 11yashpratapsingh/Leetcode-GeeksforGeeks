class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string word;
 
        // making a string stream
        stringstream iss(s);

        // Read and print each word.
        while (iss >> word) v.push_back(word);
        if(pattern.length() != v.size()) return false;
        
        unordered_map<char,string> mp;
        set<string> st;
        for(int i=0;i<pattern.length();i++){
            if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != v[i]) return false;
            }
            else{
                if(st.count(v[i])) return false;
                mp[pattern[i]] = v[i];
                st.insert(v[i]);
            }
        }
        
        return true;
    }
};