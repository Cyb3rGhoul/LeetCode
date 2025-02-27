class Solution {
public:
    int reverse(int x) {
        string h = to_string(abs((long long)x));
        std::reverse(h.begin(), h.end());
        long long rev = stoll(h);
        if(x<0) rev *= -1;
        if(rev > INT_MAX || rev < INT_MIN) return 0;
        return rev;
    }
};