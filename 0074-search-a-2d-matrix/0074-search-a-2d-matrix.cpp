class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rw = 0, cl = matrix[0].size()-1;
        while(rw<=matrix.size()-1 && cl>=0){
            if(matrix[rw][cl] == target) return true;
            else if(matrix[rw][cl] > target) cl--;
            else rw++;
        }
        
        return false;
    }
};