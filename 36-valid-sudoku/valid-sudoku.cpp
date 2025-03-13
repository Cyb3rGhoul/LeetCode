class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]=='.') continue;
                string r = string(1,board[i][j]) + "ROW" + to_string(i);
                string c = string(1,board[i][j]) + "COL" + to_string(j);
                string b = string(1,board[i][j]) + "box_row" + to_string(i/3) + "col" + to_string(j/3);

                if(st.find(r) != st.end() || st.find(c) != st.end() || st.find(b) != st.end()) return false;
                st.insert(r);
                st.insert(c);
                st.insert(b);
            }
        }
        return true;
    }
};
