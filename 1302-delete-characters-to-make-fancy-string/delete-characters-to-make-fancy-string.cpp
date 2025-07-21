class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        string res = "";
        int ctn = 1;
        for(int i = 0; i<n; i++){
            if(i>0 && s[i]==s[i-1]){
                ctn++;
                if(ctn>2) continue;
                else res += s[i];
            }else{
                ctn = 1;
                res += s[i];
            }
        }

        return res;
    }
};