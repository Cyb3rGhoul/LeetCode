class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vo;
        unordered_map<char,int> co;

        string vow = "aeiou";

        int n = s.length();

        for(int i = 0; i<n; i++){
            if(vow.find(s[i])!=string::npos){
                vo[s[i]]++;
            }else{
                co[s[i]]++;
            }
        }
        int vomaxi = 0, comaxi = 0;
        for(auto it: vo){
            vomaxi = max(vomaxi,it.second);
        }

        for(auto it: co){
            comaxi = max(comaxi,it.second);
        }

        return vomaxi + comaxi;

    }
};