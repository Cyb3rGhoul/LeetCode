bool comp1(pair<int,int> &p1, pair<int,int> &p2){
    return p1.first < p2.first;
}

bool comp2(pair<int,int> &p1, pair<int,int> &p2){
    return p1.second < p2.second;
}

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return nums;
        int r = n-1;
        // sort(nums.begin(),nums.end());

        int sum = 0;
        vector<pair<int,int>> res;
        
        while(r>=0){
            res.push_back({nums[r],r});
            r--;
        }
        sort(res.begin(),res.end(),comp1);

        vector<pair<int,int>> temp;

        for(int i = n-1; i>n-k-1; i--){
            temp.push_back(res[i]);
        }

        sort(temp.begin(),temp.end(),comp2);

        vector<int> ans;
        for(int i = 0; i<temp.size(); i++){
            ans.push_back(temp[i].first);
        }

        
        return ans;

    }
};