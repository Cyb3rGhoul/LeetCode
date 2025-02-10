class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();
        int m = s.length();
        int i = 0; 
        int j = 0;
        while(i<n){
            if(s[j]==t[i]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j<m) return false;
        return true;
    }
};