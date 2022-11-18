class Solution {
public:
 string longestPalindrome(string S){
        // code here
        int st = 0;
        int maxLen = 1;
        int n = S.length();
        
        for(int i=1;i<n;i++){
            // EVEN
            int lt = i-1, rt = i;
            while(lt>=0 && rt<n && S[lt] == S[rt]){
                if(rt-lt+1 > maxLen){
                    maxLen = rt-lt+1;
                    st = lt;
                }
                lt--, rt++;
            }
            
            // ODD
            lt = i-1, rt = i+1;
            while(lt>=0 && rt<n && S[lt] == S[rt]){
                if(rt-lt+1 > maxLen){
                    maxLen = rt-lt+1;
                    st = lt;
                }
                lt--, rt++;
            }
        }
        
        return S.substr(st,maxLen);
    }
};