class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int pres) {
        if(r == image.size() || c == image[0].size() || r < 0 || c < 0 || image[r][c] == color || image[r][c] != pres) 
            return;
        image[r][c] = color;
        dfs(image, r + 1, c, color, pres);
        dfs(image, r - 1, c, color, pres);
        dfs(image, r, c + 1, color, pres);
        dfs(image, r, c - 1, color, pres);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) 
            return image;
        int pres = image[sr][sc];
        dfs(image, sr, sc, color, pres);
        return image;
    }
};