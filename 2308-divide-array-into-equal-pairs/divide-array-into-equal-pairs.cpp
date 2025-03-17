class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n%2!=0) return false;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-1; i++){
            if(nums[i] == nums[i+1]) i++;
            else{
                return false;
            }
        }
        return true;
    }
};