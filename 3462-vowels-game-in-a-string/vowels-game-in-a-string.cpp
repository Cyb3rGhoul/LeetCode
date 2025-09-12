class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.length();
        // vector<int> freq(n,0);
        string vow = "aeiou";
        int vowctn = 0;

        for(int i = 0; i<n; i++){
            if(vow.find(s[i])!=string::npos) vowctn++;
            // else freq[i] = freq[i-1];
        }

        if(vowctn>=1) return true;
        return false;
        
    }
};