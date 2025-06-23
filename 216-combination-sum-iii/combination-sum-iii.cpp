class Solution {
public:

    void solve(vector<int> &temp, int idx, int n, vector<vector<int>> &res , int k, int sum){
        if(temp.size()==k){
            if(sum == n){
                res.push_back(temp);
            }
            return;
        }

        for(int i = idx; i<=9; i++){
            temp.push_back(i);
            sum += i;
            solve(temp, i+1, n, res, k, sum);
            sum -= i;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int minSum = (n*(n-1)/2);
        if(minSum<n) return {};

        vector<vector<int>> res;
        vector<int> temp;
        solve(temp, 1, n, res, k, 0);

        return res;
        
    }
};