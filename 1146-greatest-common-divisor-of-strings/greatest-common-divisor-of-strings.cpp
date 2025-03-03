class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        int n = str1.length();
        int m = str2.length();
        int g = gcd(m,n);
        return str1.substr(0,g);
    }
};