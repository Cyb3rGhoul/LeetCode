class Solution {
public:
    int nextSmallVal(int val, vector<int> arr, int start){
        int n = arr.size();
        for(int i = start; i<n; i++){
            if(arr[i]<=val) return arr[i];
        }
        return 0;
    }
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        for(int i =0; i<n; i++){
            int t = prices[i];
            int v = nextSmallVal(t,prices,i+1);
            ans.push_back(t-v);
        }

        return ans;
    }
};