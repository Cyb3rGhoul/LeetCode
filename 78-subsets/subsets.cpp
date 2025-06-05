class Solution {

    vector<vector<int>> res;

public:

    void solve(vector<int>& temp, vector<int>& nums, int idx){
        if(idx>=nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(temp,nums,idx+1);
        temp.pop_back();
        solve(temp,nums,idx+1);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        solve(temp,nums,0);

        return res;
    }
};