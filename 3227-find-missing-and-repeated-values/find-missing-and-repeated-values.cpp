class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<bool> mark(2500,false);
        vector<int> ans(2);
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid.size(); j++){
                if(mark[grid[i][j]]==false) mark[grid[i][j]] = true;
                else{
                    ans[0] = grid[i][j];
                }
            }
        }
        for(int i = 1; i<2501; i++){
            if(mark[i]==false){
                ans[1] = i;
                break; 
            }
        }
        return ans;
    }
};