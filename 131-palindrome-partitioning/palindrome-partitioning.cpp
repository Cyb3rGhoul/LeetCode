class Solution {
public:

    bool isPalin(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string &s, int idx, vector<string> &curr, vector<vector<string>>& res){
        if(idx==s.length()){
            res.push_back(curr);
            return; // Add this return
        }

        for(int i = idx; i<s.length(); i++){
            if(isPalin(s,idx,i)){
                 // Add this palindromic substring to current partition
                curr.push_back(s.substr(idx, i - idx + 1));
                
                // Recursively solve for remaining string
                solve(s, i + 1, curr, res);
                
                // Backtrack
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;

        vector<string> curr;

        solve(s,0,curr,res);

        // for(int i = 0; i<curr.size(); i++){
        //     cout<<curr[i]<<endl;
        // }

        return res;
    }
};