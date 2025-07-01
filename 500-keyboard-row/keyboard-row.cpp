class Solution {
public:
    bool check(string temp){
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";

        string use = "";

        if(s1.find(temp[0]) != string::npos) use = s1;
        else if(s2.find(temp[0]) != string::npos) use = s2;
        else use = s3;

        for(int i = 0; i<temp.length(); i++){
            if(use.find(temp[i])==string::npos)return false;
        }
        return true;
    }

    // void toLower(string &temp){
    //     for(char &ch: temp){
    //         ch = to_lower(ch);
    //     }
    // }
    vector<string> findWords(vector<string>& words) {
        int n = words.size();

        vector<string> res;

        for(int i = 0; i<n; i++){
            string st = words[i];
            transform(st.begin(), st.end(), st.begin(), ::tolower);
            if(check(st)){
                res.push_back(words[i]);
            }
        }

        return res;
    }
};