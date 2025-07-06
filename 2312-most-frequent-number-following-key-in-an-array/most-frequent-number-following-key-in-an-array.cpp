class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i = 0; i<n-1; i++){
            if(nums[i]==key){
                freq[nums[i+1]]++;
            }
        }

        int maxi = INT_MIN;
        int res = 0;

        for(auto &it: freq){
            // cout<<it.second<<endl;
            if(maxi < it.second){
                res = it.first;
                maxi = it.second;
            }
        }
        return res;
    }
};