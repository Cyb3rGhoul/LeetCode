class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        bool at = false;
        int ctn = 0;
        unordered_map<string,int> mp;
        string s1 = "", s2 = "";
        for(int i = 0; i<n; i++){
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
            cout<<"s1: "<<s1<<endl;
            at = false;
            for(int j = i; j<n; j++){
                if(j==i) continue;
                for(int k = 0; k<emails[j].length(); k++){
                    if(emails[j][k]=='.' && !at) continue;
                    else if(emails[j][k]=='+' && !at){
                        while(emails[j][k]!='@'){
                            k++;
                        }
                        s2+='@';
                        at = true;
                    }
                    else if(emails[j][k]=='@'){
                        s2+='@';
                        at = true;
                    }
                    else{
                        s2 += emails[j][k];
                    }
                }
                at = false;
                cout<<"s2: "<<s2<<endl;
                mp[s2]++;
                s2.erase();
            }
            mp[s1]++;
            s1.erase();
        }
        return mp.size();
    }
};