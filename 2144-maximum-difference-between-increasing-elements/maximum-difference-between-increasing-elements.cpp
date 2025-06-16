class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxNum(n);
        maxNum[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            maxNum[i] = max(maxNum[i+1],nums[i]);
        }
        int diff = -1;
        for(int i = 0; i<n; i++){
            diff = max(diff,maxNum[i]-nums[i]);
        }

        return diff==0?-1:diff;
        
    }
};