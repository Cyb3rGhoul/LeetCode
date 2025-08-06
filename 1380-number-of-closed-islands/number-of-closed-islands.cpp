class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis, bool& noBound){
        if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || vis[r][c] || grid[r][c] == 1) {
            return;
        }
        if(r==0 || r==grid.size()-1 || c==0 || c==grid[0].size()-1){ 
            noBound = false;
            return;
        }

        vis[r][c] = true;
        dfs(grid,r+1,c,vis,noBound);
        dfs(grid,r-1,c,vis,noBound);
        dfs(grid,r,c+1,vis,noBound);
        dfs(grid,r,c-1,vis,noBound);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ctn = 0;
        vector<vector<pair<int,int>>> res;
        vector<pair<int,int>> temp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    bool noBound = true;
                    dfs(grid,i,j,vis,noBound);
                    if(noBound) ctn++;
                }
            }
        }

        return ctn;
    }
};