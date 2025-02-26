class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumEven = 0;
        int n = nums.size();
        vector<int> res(n);

        for(int i = 0; i<n; i++){
            if(nums[i]%2==0) sumEven += nums[i];
        }
        for(int i = 0; i<queries.size(); i++){
            int val = queries[i][0];
            int idx = queries[i][1];
            if(nums[idx]%2==0){
                if(val%2==0) sumEven += val;
                else{
                    sumEven -= nums[idx];
                }
            }else{
                if(val%2!=0) sumEven += (val+nums[idx]);
            }
            nums[idx] += val;
            res[i] = sumEven;
        }
        return res;
    }
};