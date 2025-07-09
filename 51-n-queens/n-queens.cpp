class Solution {
public:
    vector<vector<string>> res;
    int N;
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antidiag;

    void solve(vector<string>& board, int row){
        if(row>=N){
            res.push_back(board);
        }
        for(int col = 0; col < N; col++){
                int dia = row+col;
                int antidia = row-col;
                if(cols.find(col)!=cols.end() || diag.find(dia)!=diag.end() || antidiag.find(antidia) != antidiag.end()) continue;

                board[row][col] = 'Q';
                cols.insert(col);
                diag.insert(dia);
                antidiag.insert(antidia);

                solve(board,row+1);

                board[row][col] = '.';
                cols.erase(col);
                diag.erase(dia);
                antidiag.erase(antidia);

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n,string(n,'.'));

        solve(board,0);

        return res;

    }
};