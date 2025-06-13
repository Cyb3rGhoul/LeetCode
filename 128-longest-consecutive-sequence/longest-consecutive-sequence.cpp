class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 1;
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());

        for(int i = 0; i<n-1; i++){
            int currLen = 1;
            if(nums[i]==nums[i+1]-1){
                while(i<n-1 && nums[i]==nums[i+1]-1){
                    currLen++;
                    i++;
                    while(i<n-1 && nums[i]==nums[i+1]) i++;
                }
            }
            len = max(currLen,len);
        }

        return len;
    }
};