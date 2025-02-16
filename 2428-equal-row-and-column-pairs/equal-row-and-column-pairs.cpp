class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;
        int ctn = 0;

        
        for (int i = 0; i < n; i++) {
            mp[grid[i]]++;
        }

        
        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]); 
            }
            if (mp.find(col) != mp.end()) { 
                ctn += mp[col];
            }
        }

        return ctn;
    }
};