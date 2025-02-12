class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        string vow = "aeiou";
        int ctn = 0;
        for(int i = 0; i<k; i++){
            if(vow.find(s[i]) != string::npos){
                ctn++;
            }
        }
        int curr = ctn;
        for(int i = k; i<n; i++){
            char ch = s[i];
            char ol = s[i-k];
            if(vow.find(ch) != string::npos) curr++;
            if(vow.find(ol) != string::npos) curr--;
            ctn = max(ctn,curr);
        }
        return ctn;
    }
};