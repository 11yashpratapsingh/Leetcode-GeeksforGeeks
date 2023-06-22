class Solution {
public:
    int missingNumber(vector<int>& A) {
        int xor1 = 0, xor2 = 0, n= A.size();
        for(int i=0;i<n;i++){
            xor2= xor2^A[i];
            xor1 = xor1^(i);
        }

        xor1 = xor1^n;

        return xor1^xor2;
    }
};