class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        
        int ctn = 0;
        unordered_set<string> st;
        string s1 = "";
        for(int i = 0; i<n; i++){
            bool at = false;
            for(int k = 0; k<emails[i].length(); k++){
                if(emails[i][k]=='.' && !at) continue;
                else if(emails[i][k]=='+' && !at){
                    while(emails[i][k]!='@'){
                        k++;
                    }
                    s1+='@';
                    at = true;
                }
                else if(emails[i][k]=='@'){
                    at = true;
                    s1+='@';
                }else{
                    s1 += emails[i][k];
                }
            }
            st.insert(s1);
            s1.erase();
        }
        return st.size();
    }
};