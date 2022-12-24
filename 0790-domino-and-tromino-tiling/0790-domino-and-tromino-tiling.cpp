class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9+7;
        int a=0,b=1,c=1,d;
        for(int i=2;i<=n;i++){
            d = ((2*c)%mod + a)%mod;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};