class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while (i < n - 1 && nums[i] <= nums[i + 1]) {
        i++;
        }
        if(i==n-1) return true;
        int j = i+1;
        while(j<n-1 && nums[j]<=nums[j+1]){
            j++;
        }
        if(j!=n-1) return false;
        return nums[n-1]<=nums[0];
    }
};