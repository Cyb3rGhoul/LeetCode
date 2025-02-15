class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);  // Fixed size from 25 to 26

        int n = word1.length();
        int m = word2.length();

        if (n != m) return false;

        for (int i = 0; i < n; i++) {
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }

        // Check if both words have the same unique characters
        for (int i = 0; i < 26; i++) {
            if ((f1[i] == 0) ^ (f2[i] == 0))  // XOR condition to check for mismatched presence
                return false;
        }

        // Sort the frequency counts
        sort(begin(f1), end(f1));
        sort(begin(f2), end(f2));

        // Compare frequency distributions
        for (int i = 0; i < 26; i++) {  // Fixed loop range from 0 to 25
            if (f1[i] != f2[i]) return false;
        }
        return true;
    }
};
