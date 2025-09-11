class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        for(int i = 0; i<n; i++){
            freq[s[i]-'a']++;
        }
        int curr = 0;
        for(int i = 0; i<26; i++){
            if(curr==0 && freq[i]!=0){
                curr = freq[i];
            }
            else if(freq[i]!=0 && curr!=freq[i])return false;
        }
        return true;
    }
};