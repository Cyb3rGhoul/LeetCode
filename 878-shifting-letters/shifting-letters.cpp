class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<int> pref(n);
        pref[n-1] = (shifts[n-1])%26;

        for(int i = n-2; i>=0; i--){
            int val = (pref[i+1])%26;
            pref[i] = (shifts[i] + val)%26;
        }
        
        string res = "";
        for(int i = 0; i<n; i++){
            int num = s[i] + pref[i];
            while(num>122) {
                num -= 122; 
            }
            if(num<96){
                res += 'a' + num - 1;
                continue;
            }
            res += s[i] + pref[i];
        }
        return res;

    }
};