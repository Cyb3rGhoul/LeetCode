class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        string vowels = "aeiouAEIOU";

        while (i < j) {
            // Move i forward if it's not a vowel
            while (i < j && vowels.find(s[i]) == string::npos) i++;

            // Move j backward if it's not a vowel
            while (i < j && vowels.find(s[j]) == string::npos) j--;

            // Swap vowels
            swap(s[i], s[j]);

            // Move pointers
            i++;
            j--;
        }
        return s;
    }
};
