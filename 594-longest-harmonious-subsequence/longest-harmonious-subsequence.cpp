class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;

        int n = nums.size();

        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        int res = 0;
        for(auto &it: mp){
            int num = it.first;
            int freq = 0;

            if(mp.find(num+1)!=mp.end()){
                freq += (it.second+mp[num+1]); 
            }

            else if(mp.find(num-1)!=mp.end()){
                freq += (it.second+mp[num-1]);
            }

            res = max(res,freq);
        }

        return res;
    }
};