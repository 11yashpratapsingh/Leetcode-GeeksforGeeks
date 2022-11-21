class Solution {
public:
    
    vector<int> dx = {1 , -1 ,  0 , 0}, dy = {0 ,  0 , -1 , 1};
    int m,n;
    
    bool isValid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        m = maze.size(), n = maze[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n,0));
        queue<pair<int,int>> q;
        
        vis[ent[0]][ent[1]] = 1;
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
                    if(x>=0 && y>=0 && x<m && y<n){
                        if(maze[x][y] != '.' || vis[x][y]) continue;
                    
                        if(x == 0 || y == 0 || x == m-1 || y == n-1) return move;

                        vis[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};