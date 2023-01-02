class Solution {
public:
    bool detectCapitalUse(string st) {
        int n = st.length();
        
        if(isupper(st[0]) && isupper(st[1])){
            for(int i=2;i<n;i++){
                if(islower(st[i])) return false;
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(isupper(st[i])) return false;
            }
        }
        
        return true;
    }
};