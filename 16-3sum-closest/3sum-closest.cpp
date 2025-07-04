class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = INT_MAX;
        int res = 0;
        for(int i = 0; i<n-2; i++){
            for(int j = i+1; j<n-1; j++){
                for(int k = j+1; k<n; k++){
                    
                        int l = abs(nums[i]+nums[j]+nums[k]-target);
                        if(l<sum){
                            sum = min(sum,l);
                            res = nums[i]+nums[j]+nums[k];
                        }
                }
            }
        }
        return res;
    }
};