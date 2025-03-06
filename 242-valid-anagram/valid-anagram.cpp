class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ch(26,0);
        for(int i =0; i<s.length(); i++){
            ch[s[i]-'a']++;
        }
        for(int i =0; i<t.length(); i++){
            ch[t[i]-'a']--;
            if(ch[t[i]-'a']<0) return false;
        }
        for(int i = 0; i<26; i++){
            if(ch[i]!=0) return false;
        }
        return true;
    }
};