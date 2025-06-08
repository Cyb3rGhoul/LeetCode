class Solution {
public:
    void solve(vector<int>& a, vector<int>& ip, vector<vector<int>>& res, int target, int idx){
        if(idx==a.size()){
            if(target==0){
                res.push_back(ip);
            }
            return;
        }
        
        if(a[idx]<=target){
            ip.push_back(a[idx]);
            solve(a,ip,res,target-a[idx],idx);
            ip.pop_back();
        }

        solve(a,ip,res,target,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ip;

        solve(candidates,ip,res,target,0);

        return res;
    }
};