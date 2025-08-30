class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for(int j = 0; j<m; j++){
            for(int i = 0; i<n; i++){
                if(i>0 && grid[i][j]<=grid[i-1][j]){
                    int add = grid[i-1][j]-grid[i][j] + 1;
                    ans += add;
                    grid[i][j] += add;
                }
            }
        }
        return ans;

    }
};