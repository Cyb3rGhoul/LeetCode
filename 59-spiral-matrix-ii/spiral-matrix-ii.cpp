class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = 0, b = n-1, r = n-1, l = 0;
        int ctn = 1;
        vector<vector<int>> res(n,vector<int>(n));
        while(t<=b && l<=r){
            for(int i = l; i<=r; i++){
                res[t][i] = ctn++;
            }
            t++;

            for(int i = t; i<=b; i++){
                res[i][r] = ctn++;
            }
            r--;

            for(int i = r; i>=l; i--){
                res[b][i] = ctn++;
            }
            b--;

            for(int i = b; i>=t; i--){
                res[i][l] = ctn++;
            }
            l++;
        }

        return res;
    }
};