class Solution {
public:
    int scoreOfString(string s) {
        int num = 0;
        int l = 0;
        while(l<s.size()-1){
            num += abs(int(s[l]) - int(s[l+1]));
            l++;
        }
        return num;
    }
};