class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> mp;
        int n = bannedWords.size();
        int m = message.size();
        for(int i = 0; i<n; i++){
            mp[bannedWords[i]]++;
        }
        int ctn = 0;
        for(int i = 0; i<m; i++){
            if(mp.find(message[i])!=mp.end()) ctn++;
        }
        return ctn >= 2 ? true : false;
    }
};