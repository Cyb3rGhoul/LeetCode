class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i]; // nums ko add karo
            maxi = max(sum,maxi); // maxi ko update karo
            if(sum<0) sum = 0; // agar sum less ko to usko update karne ki zarurat
        }

        return maxi;
    }
};