class Solution {
public:
    bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    
    // Traverse both strings
    while (i < s.length() && j < t.length()) {
        // If characters match, move the pointer for `s`
        if (s[i] == t[j]) {
            i++;
        }
        // Always move the pointer for `t`
        j++;
    }
    
    // If all characters of `s` were found in `t` in order
    return i == s.length();
}

};