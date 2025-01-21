class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int num = 1;
        for(int i = 0; i<n; i++){
            if(i==0) ans[i] = 1;
            else{
            ans[i] = nums[i-1]*ans[i-1];
            }
        }
        for(int i = n-2; i>=0; i--){
            num *= nums[i+1];
            ans[i] *= num;
        }
        return ans;
    }
};