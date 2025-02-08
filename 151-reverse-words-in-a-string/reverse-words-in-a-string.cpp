class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        stack<string> st;
        string word = "";

        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }

                while (i < n && s[i] == ' ') i++;
            } else {
                word += s[i];  // Build word
                i++;
            }
        }

        if (!word.empty()) {
            st.push(word);
        }

        // Construct reversed sentence
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " "; // Add space between words
        }

        return ans;
    }
};