class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false));
        vector<vector<bool>> alt(n,vector<bool>(m,false));

        for(int c = 0; c<m; ++c){
            dfs(0,c,pac,heights);
            dfs(n-1,c,alt,heights);
        }

        for(int r = 0; r<n; ++r){
            dfs(r,0,pac,heights);
            dfs(r,m-1,alt,heights);
        }

        vector<vector<int>> res;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pac[i][j] && alt[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }

    private:
        void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
            ocean[r][c] = true;
            for(auto [dr,dc]:dir){
                int nr = r + dr, nc = c + dc;
                if(nc >= 0 && nr>=0 && nr<heights.size() && nc <heights[0].size() &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    dfs(nr,nc,ocean,heights);
                }
            }
        }
};