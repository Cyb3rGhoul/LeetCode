class Solution {

    map<vector<int>, int> mp;

public:

    void solve(vector<int>& temp, vector<int>& nums, int idx){
        if(idx>=nums.size()){ 
            if(temp.size()!=0);
            mp[temp]++;
            return;
        }

        temp.push_back(nums[idx]); // explore when we took the digit    
        solve(temp,nums,idx+1); // solve it when the digit is included
        temp.pop_back(); // explore when we dont take the digit
        solve(temp,nums,idx+1); // solve it when the digit is not included


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end()); // kyu sort hua mujhe samjh nahi aaya

        solve(temp,nums,0);

        vector<vector<int>> ans;

        for(auto it: mp){ //taki duplicate na ho
            ans.push_back(it.first);
        }

        return ans;
    }
};