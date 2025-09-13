class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int num = 1;
        int ctn = 0;

        int top = 0, bottom = n - 1, left = 0, right = n - 1;

        // Iterate until all elements are stored
        while (top <= bottom && left <= right) {

            // store top row from left to right
            for (int i = left; i <= right; ++i) {
                res[top][i] = num++;
            }
            top++;

            // store right column from top to bottom
            for (int i = top; i <= bottom; ++i) {
                res[i][right] = num++;
            }
            right--;

            // store bottom row from right to left (if exists)
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    res[bottom][i] = num++;
                }
                bottom--;
            }

            // store left column from bottom to top (if exists)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res[i][left] = num++;
                }
                left++;
            }
        }
        return res;
    }
};