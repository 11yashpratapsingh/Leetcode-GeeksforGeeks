class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9), col(9), block(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                if(row[i].count(val) || col[j].count(val) || block[(i/3)*3+j/3].count(val)) return false;
                
                row[i].insert(val);
                col[j].insert(val);
                block[(i/3)*3+j/3].insert(val);
            }
        }
        return true;
    }
};