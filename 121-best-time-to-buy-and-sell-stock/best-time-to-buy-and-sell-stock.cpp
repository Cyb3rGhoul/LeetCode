class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int n = prices.size();
        int num = prices[0];

        for(int i = 1; i<n; i++){
            if(num > prices[i]){
                num = prices[i];
            }else if(prices[i]-num>prof){
                prof = prices[i]-num;
            }
        }
        return prof;
    }
};