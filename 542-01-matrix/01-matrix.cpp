class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> res(n,vector<int>(m));
        queue<pair<pair<int,int>,int>> q;

        for(int r = 0; r<n; r++){
            for(int c = 0; c<m; c++){
                if(mat[r][c] == 0){
                    q.push({{r,c},0});
                    vis[r][c] = true;
                    res[r][c] = 0;
                }
            }
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for(auto [dr,dc] : dir){
                int nr = row + dr;
                int nc = col + dc;

                if(nr>=0 && nc>=0 && nr<n && nc<m  && mat[nr][nc] == 1 && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({{nr,nc},d+1});
                    res[nr][nc] = d+1;
                }
            }
        }

        return res;

    }
};