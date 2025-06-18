class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i<n-2; i++){
            vector<int> temp;            
            if(nums[i+2]-nums[i] <= k){
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                res.push_back(temp);
                i = i + 2;
            }
            else{
                return {};
            }
        }
        return res;
    }
};