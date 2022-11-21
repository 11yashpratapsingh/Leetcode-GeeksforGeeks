class Solution {
public:
    
    vector<int> dx = {0,1,0,-1}, dy = {1,0,-1,0};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int,int>> q;
        
        maze[ent[0]][ent[1]] = '+';
        q.push({ent[0],ent[1]});
        int move = 0;
        
        while(!q.empty()){
            int sz = q.size();
            move++;
            while(sz--){
                auto curr = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = curr.first + dx[i], y = curr.second + dy[i];
                    if(x<0 || y<0 || x>=m || y>=n || maze[x][y] == '+') continue;
                    if(x==0 || y==0 || x==m-1 || y == n-1) return move;
                    maze[x][y] = '+';
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
};