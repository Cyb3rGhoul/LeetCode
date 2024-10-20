class Solution {
public:
    
        int greatestProperDivisor(int x) {
            int largestDivisor = 1;  

            for (int i = 1; i * i <= x; ++i) {
                if (x % i == 0) {
                    int div1 = i;
                    int div2 = x / i;

                    if (div1 < x) {
                        largestDivisor = std::max(largestDivisor, div1);
                    }
                    if (div2 < x) {
                        largestDivisor = std::max(largestDivisor, div2);
                    }
                }
            }

            return largestDivisor;  
        }
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = n - 2; i >= 0; --i) {
            if(nums[i]<=nums[i+1])continue;
            
            int gpd = greatestProperDivisor(nums[i]);
            if(gpd==nums[i])return -1;
            nums[i] /= gpd;
            if(nums[i]>nums[i+1])return -1;
            operations++;
        }

        return operations;
    }
};