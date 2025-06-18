class Solution {
    int solve(string s, int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return r - l - 1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0) return "";

        int start = 0;
        int e = 0;

        for(int i = 0; i<n; i++){
            int odd = solve(s,i,i);
            int eve = solve(s,i,i+1);

            int maxi = max(odd,eve);

            if(maxi > e-start){
                start = i - (maxi - 1)/2;
                e = i + (maxi)/2;
            }
        }

        return s.substr(start,e-start+1);
        
    }
};