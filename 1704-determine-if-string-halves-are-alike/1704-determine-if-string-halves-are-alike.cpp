class Solution {
public:
    string vowels = "aeiouAEIOU";
    
    bool halvesAreAlike(string s) {
        int mid = s.length()/2, cnt = 0;
        for(int i=0,j=mid;i<mid;i++,j++){
            if(~vowels.find(s[i])) cnt++;
            if(~vowels.find(s[j])) cnt--;
        }
        
        return cnt == 0;
    }
};