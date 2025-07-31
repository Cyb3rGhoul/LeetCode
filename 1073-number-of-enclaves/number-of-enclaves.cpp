class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        //row filling
        for(int i = 0; i<n; i++){
            if(grid[i][0]==1){
                q.push({i,0});
                vis[i][0] = true;
            } 
            if(grid[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1] = true;
            }
        }
        //col filling
        for(int i = 0; i<m; i++){
            if(grid[0][i]==1){
                q.push({0,i});
                vis[0][i] = true;
            } 
            if(grid[n-1][i]==1){
                q.push({n-1,i});
                vis[n-1][i] = true;
            }
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto [dr,dc] : dir){
                int nr = r+dr;
                int nc = c+dc;

                if(nr<n && nc<m && nr>=0 && nc>=0 && !vis[nr][nc] && grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc] = true;
                }
            }
        }
        int ctn = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j] == false) ctn++;
            }
        }
        return ctn;
    }
};