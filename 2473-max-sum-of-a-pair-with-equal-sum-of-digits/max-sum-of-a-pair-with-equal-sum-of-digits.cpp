class Solution {
public:
    int getSum(int num){
        int sum = 0;
        while(num>0){
            sum += (num%10);
            num /=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        int res = -1;
        
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++){
            int a = getSum(nums[i]);
            if(mp.count(a)){
                res = max(res, nums[i]+mp[a]);
            }
            mp[a] = max(mp[a],nums[i]);
        }
        return res;
    }
};