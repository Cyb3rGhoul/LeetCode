class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size();
        if(boardingCost * 4 <= runningCost) return -1;
        int round = -1, rem = 0, curr = 0;
        int maxi = 0;
        for(int i = 0; i<n || rem; ++i){
            if(i<n) rem += customers[i];
            curr += min(rem,4) * boardingCost - runningCost;
            rem -= min(rem,4);
            if(maxi<curr){
                maxi = curr;
                round = i + 1;
            }
        }

        return round;
    }
};