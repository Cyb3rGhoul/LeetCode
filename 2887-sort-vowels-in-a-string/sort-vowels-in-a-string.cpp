class Solution {
public:
    string sortVowels(string s) {
        string res = "";

        int n = s.length();

        string vow = "aeiouAEIOU";
        vector<char> vec;
        for(int i = 0; i<n; i++){
            if(vow.find(s[i])!=string::npos){
                vec.push_back(s[i]);
            }
        }
        sort(vec.begin(),vec.end());
        int idx = 0;
        
        for(int i = 0; i<n; i++){
            if(vow.find(s[i])!=string::npos){
                res += vec[idx++];
            }
            else res += s[i];
        }

        return res;   
    }
};