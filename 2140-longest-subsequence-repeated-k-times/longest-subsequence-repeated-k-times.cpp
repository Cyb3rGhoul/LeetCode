class Solution {
public:
    bool isSub(string &s, string& sub, int k){
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();
        
        while(i < n && j < k * L){
            if(s[i] == sub[j % L]){
                j++;
            }
            i++;
        }
        
        return j == k * L;
    }
    
    bool solve(string &s, string &curr, vector<bool>& can, vector<int>& req, int k, int maxLen, string& res){
        if(curr.length() == maxLen){
            if(isSub(s,curr,k)){
                res = curr;
                return true;
            }
            return false;
        }
        
        for(int i = 25; i >=0; i--){
            if(can[i] == false || req[i] == 0) continue;
            
            // DO
            char ch = i + 'a';
            curr.push_back(ch);
            req[i]--;
            
            // Explore
            if(solve(s, curr, can, req, k, maxLen, res)) return true;
            
            // Undo
            curr.pop_back();
            req[i]++;
        }
        return false;
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        
        int freq[26] = {};
        for(char &ch: s){
            freq[ch-'a']++;
        }
        
        vector<bool> can(26, false);
        vector<int> req(26, 0);
        for(int i = 0; i < 26; i++){
            if(freq[i] >= k) {
                can[i] = true;
                req[i] = freq[i] / k;
            }
        }
        int maxLen = n / k;
        
        string curr;
        string res = ""; // Make res local instead of class member
       

        for(int len = maxLen; len>=0; len--){
            vector<int> tempReq = req;
            if(solve(s,curr,can,tempReq,k,len, res)==true){
                return res;
            }
        }
        
        return res;
    }
};