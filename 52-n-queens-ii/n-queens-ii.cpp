class Solution {
public:

    
    void solve(int row, int n, vector<bool> &column, vector<bool> &antiDia, vector<bool> &dia, int &res){
        if(row == n){
            res++;
            return;
        }

        for(int i = 0; i<n; i++){
            if(!column[i] && !antiDia[row+i] && !dia[row-i+n-1]){
                column[i] = true;
                antiDia[row+i] = true;
                dia[row-i+n-1] = true;
                solve(row+1,n,column,antiDia,dia,res);
                column[i] = false;
                antiDia[row+i] = false;
                dia[row-i+n-1] = false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<bool> column(n,false);
        vector<bool> antiDia(2*n-1,false);
        vector<bool> dia(2*n-1,false);
        int res = 0;
        solve(0,n,column,antiDia,dia,res);
        return res;
    }
};