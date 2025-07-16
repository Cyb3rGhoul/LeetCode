class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0, ctn = 0;

        for(int num: nums){
            sum += num;

            if(mp.find(sum-k)!=mp.end()){
                ctn += mp[sum-k];
            }
            mp[sum]++;
        }
        return ctn;
    }
};