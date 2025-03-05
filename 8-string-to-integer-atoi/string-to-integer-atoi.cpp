class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        int sign = 1;
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        long long num = 0;
        while(i<s.length() && s[i]=='0'){
            i++;
        }
        if(i==s.length()) return 0;

        while (i < s.length() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            if (num > INT_MAX) return (sign == 1) ? INT_MAX : INT_MIN;

            i++;
        }

        return num * sign;
    }
};