class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<int> pref(n);
        pref[n-1] = shifts[n-1];

        for(int i = n-2; i>=0; i--){
            int val = (pref[i+1]);
            pref[i] = (shifts[i] + val)%26;
        }
        
        for(int i = 0; i<n; i++){
            s[i] = ('a'+(s[i]-'a'+pref[i])%26);
        }
        return s;

    }
};