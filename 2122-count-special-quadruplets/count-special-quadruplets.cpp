class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        // unordered_map<int,int> mp;
        int ctn = 0;
        int n = nums.size();
        for(int i =0 ;i<n-3; i++){
            for(int j = i+1;j<n-2; j++){
                for(int k = j+1; k<n-1; k++){
                    for(int l = k+1; l<n; l++){
                        if(nums[i]+nums[j]+nums[k]==nums[l]) ctn++;
                    }
                }
            }
        }

        return ctn;
    }
};