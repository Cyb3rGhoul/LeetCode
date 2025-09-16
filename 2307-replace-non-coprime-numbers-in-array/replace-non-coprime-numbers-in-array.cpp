class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        
        for(int num : nums) {
            res.push_back(num);
            
            // Keep merging backwards while possible
            while(res.size() > 1 && gcd(res[res.size()-2], res.back()) > 1) {
                int last = res.back();
                res.pop_back();
                int secondLast = res.back();
                res.pop_back();
                res.push_back(lcm(secondLast, last));
            }
        }
        
        return res;
    }
};