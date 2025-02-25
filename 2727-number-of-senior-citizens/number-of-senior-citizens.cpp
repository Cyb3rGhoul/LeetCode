class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int ctn = 0;
        for(int i = 0; i<n; i++){
            string age = details[i].substr(11, 2);
            if(stoi(age)>60) ctn++;
        }
        return ctn;
    }
};