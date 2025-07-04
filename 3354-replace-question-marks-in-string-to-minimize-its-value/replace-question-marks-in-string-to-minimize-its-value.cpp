class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.length();
        vector<int> count(26, 0);
        int questionMarks = 0;
        
        // Count existing characters and question marks
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                count[c - 'a']++;
            } else {
                questionMarks++;
            }
        }
        
        // Generate characters to fill question marks
        string toFill = "";
        for (int i = 0; i < questionMarks; i++) {
            // Find character with minimum count
            int minCount = INT_MAX;
            int minIdx = 0;
            for (int j = 0; j < 26; j++) {
                if (count[j] < minCount) {
                    minCount = count[j];
                    minIdx = j;
                }
            }
            
            // Add this character and update its count
            toFill += ('a' + minIdx);
            count[minIdx]++;
        }
        
        // Sort the characters to ensure lexicographically smallest result
        sort(toFill.begin(), toFill.end());
        
        // Replace question marks with sorted characters
        string result = "";
        int fillIdx = 0;
        for (char c : s) {
            if (c == '?') {
                result += toFill[fillIdx++];
            } else {
                result += c;
            }
        }
        
        return result;
    }
};