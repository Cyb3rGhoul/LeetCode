class Solution {
public:
    int MOD = 1e9+7;

    int solve(int r, int c, vector<vector<int>>& grid, int prev, vector<vector<int>> &dp){
        if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid[r][c] <= prev) return 0;
        // cout<<grid[r][c]<<endl;
        // tot++;
        if(dp[r][c]!=-1) return dp[r][c];
        int t = solve(r+1,c,grid,grid[r][c],dp);
        int b = solve(r-1,c,grid,grid[r][c],dp);
        int ri = solve(r,c+1,grid,grid[r][c],dp);
        int l = solve(r,c-1,grid,grid[r][c],dp);

        dp[r][c] = (1+t+b+ri+l)%MOD;

        return dp[r][c];

    }
    int countPaths(vector<vector<int>>& grid) {
        // long long tot = 0; 
        int n = grid.size();
        int m = grid[0].size();
        if(m==1 && n==1) return 1;
        vector<vector<int>> dp(n,vector(m,-1));
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(dp[i][j]==-1) ans = (ans+solve(i,j,grid,-1,dp))%MOD;
                else ans = (ans + dp[i][j])%MOD;
            }
        }
        return ans;
    }
};