class Solution {
public:
    void solve(vector<int> &nums, int idx, vector<int> &temp, unordered_map<int,vector<vector<int>>> &mp, int sum){
        if(idx == nums.size()){
            mp[sum].push_back(temp);
            return;
        }
        
        // Include current element
        temp.push_back(nums[idx]);
        solve(nums, idx+1, temp, mp, sum | nums[idx]);
        temp.pop_back();
        
        // Exclude current element  
        solve(nums, idx+1, temp, mp, sum);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int,vector<vector<int>>> mp;
        vector<int> temp;
        solve(nums, 0, temp, mp, 0);
        
        int ans = 0;
        int maxi = INT_MIN;
        for(auto &it: mp){
            cout << it.first << " " << it.second.size() << endl;
            if(maxi < it.first){
                maxi = it.first;
                ans = it.second.size(); 
            }
        }
        return ans;
    }
};
