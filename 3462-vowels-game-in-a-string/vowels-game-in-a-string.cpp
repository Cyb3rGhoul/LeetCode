class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.length();
        vector<int> freq(n,0);
        string vow = "aeiou";
        if(vow.find(s[0])!=string::npos) freq[0] = 1;

        for(int i = 1; i<n; i++){
            if(vow.find(s[i])!=string::npos) freq[i] = freq[i-1] + 1;
            else freq[i] = freq[i-1];
        }

        if(freq[n-1]==0) return false;
        if(freq[n-1]==1||freq[n-1]%3==0||(freq[n-1]-1)%3==0||(freq[n-1]+1)%3==0) return true;
        return false;
        
    }
};