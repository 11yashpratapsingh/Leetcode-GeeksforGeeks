class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        
        string st = "11";
        int cnt = 1;
        for(int i=3;i<=n;i++){
            st += '$';
            int len = st.length();
            string temp = "";
            for(int j=1;j<len;j++){
                if(st[j]!=st[j-1]){
                    temp += cnt + '0';
                    temp += st[j-1];
                    cnt = 1;
                }
                else cnt++;
            }
            
            st = temp;
        }
        
        return st;
    }
};