class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n<3) return false;
        bool isVal1 = false;//digit
        bool isVal4 = false; //alphabet
        bool isVal2 = false; //vovwel;
        bool isVal3 = false; //3 consonents

        string vow = "aeiouAEIOU";

        for(int i = 0; i<n; i++){
            if((s[i]>='0' && s[i]<='9') || isalpha(s[i])){
                if(isalpha(s[i])){
                    isVal4 = true; //alphabet;
                    if(vow.find(s[i])!=string::npos) isVal2 = true; // vowel
                    else isVal3 = true; //consonent
                }
                else isVal1 = true; //number
            }
            else return false;
        }

        return (isVal1 || isVal4) && isVal3 && isVal2;
    }
};