class Solution {
    
    vector<vector<int>> res;
public:
    void solve(vector<int>& a, vector<int>& temp, int idx, int target){
        
            if(target==0){
                res.push_back(temp);
                return;
            }
            for(int i = idx; i<a.size(); i++){
                if(i>idx && a[i] == a[i-1]) continue;
                if(a[i]>target) break;
                temp.push_back(a[i]);
                solve(a,temp,i+1,target-a[i]);
                temp.pop_back();
                // solve(a,temp,idx+1,target);

            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,temp,0,target);
        return res;
    }
};