class Solution {
public:
    bool isPowerOfTwo(int n) {
        if((n!=1 && n%2!=0) || n==0) return false;
        if(n==1) return true;

        return isPowerOfTwo(n/2);
    }
};