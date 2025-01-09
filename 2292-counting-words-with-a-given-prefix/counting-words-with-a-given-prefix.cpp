class Solution {
public:
    bool isPref(string word, string pref){
        int i = 0;
        int n = word.length();
        while(i<pref.length()){
            if(pref[i]!=word[i]) return false;
            i++;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(string word:words){
            if(isPref(word,pref)) count++;
        }
        return count;
    }
};