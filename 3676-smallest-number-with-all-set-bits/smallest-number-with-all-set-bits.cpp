class Solution {
public:
    int smallestNumber(int n) {
        string res = "";
        while(n!=0){
            int a = n%2;
            res += (a+'0');
            n/=2;
        }
        int m = res.length();
        return pow(2,m)-1;
    }
};