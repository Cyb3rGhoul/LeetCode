class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length()<k){
            string curr = "";
            for(int i = 0; i<s.length(); i++){
                if(s[i]=='z'){
                    curr += 'a';
                    continue;
                }
                curr += (char)(s[i] + 1);
            }
            s+=curr;
        }
        cout<<s;
        return s[k-1];

    }
};