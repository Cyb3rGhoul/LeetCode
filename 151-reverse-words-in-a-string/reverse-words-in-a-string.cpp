class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> res;
        int i = 0;
        int n = s.length();
        while(s[i]==' '){
            i++;
        }
        while(s[n-1]==' '){
            n--;
        }
        string word = "";
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            while(i<n && s[i]!=' '){
                word += s[i];
                i++;
            }
            res.push(word);
            word = "";
            i++;
        }
        while(!res.empty()){
            ans += res.top();
            res.pop();
            if(!res.empty()) ans += " ";
        }
        return ans;
        
    }
};