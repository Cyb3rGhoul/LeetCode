class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int tup = 0;
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto &it: mp){
            int prod = it.first;
            int freq = it.second;
            tup += (freq * (freq-1)/2);
        }
        return tup*8;
    }
};