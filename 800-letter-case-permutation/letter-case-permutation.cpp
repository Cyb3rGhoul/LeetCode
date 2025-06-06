class Solution {
public:
    vector<string> ans;

    void solve(string op, string s) {
        if(s.length() == 0) {
            ans.push_back(op);
            return;
        }

        char ch = s[0];
        s.erase(s.begin());

        if(isdigit(ch)) {
            solve(op + ch, s);
        } else {
            solve(op + (char)tolower(ch), s);
            solve(op + (char)toupper(ch), s);
        }
    }

    vector<string> letterCasePermutation(string s) {
        solve("", s);
        return ans;
    }
};