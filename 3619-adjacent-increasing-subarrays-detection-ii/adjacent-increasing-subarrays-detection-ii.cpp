class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
         int n = nums.size();
        
        vector<int> incLen(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                incLen[i] = incLen[i + 1] + 1;
            }
        }
        
        int l = 1, r = n / 2, maxK = 0;
        
        while (l <= r) {
            int k = l + (r - l) / 2;
            bool found = false;
            
            for (int i = 0; i <= n - 2 * k; ++i) {
                if (incLen[i] >= k && incLen[i + k] >= k) {
                    found = true;
                    break;
                }
            }
            
            if (found) {
                maxK = k;
                l = k + 1;
            } else {
                r = k - 1;
            }
        }
        
        return maxK;
    }
};