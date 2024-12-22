class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = n;
        for(int i = 0; i<n; i++){
            if(nums[i]==val) {
                k--;
                nums[i] = INT_MAX;
            }
        }
        sort(nums.begin(),nums.end());

        return k;
    }
};