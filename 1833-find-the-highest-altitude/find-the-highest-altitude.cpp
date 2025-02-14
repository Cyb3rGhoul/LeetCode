class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int curr = 0;
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i<n+1; i++){
            int res = (gain[i-1]+ans[i-1]);
            ans.push_back(res);
            curr = max(curr,res);
        }
        return curr;
    }
};