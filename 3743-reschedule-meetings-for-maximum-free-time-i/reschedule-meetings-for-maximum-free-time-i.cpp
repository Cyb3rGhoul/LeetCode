class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gap(1,startTime[0]);
        for(int i = 1; i<startTime.size(); i++){
            gap.push_back(startTime[i]-endTime[i-1]);
        }
        gap.push_back(eventTime-endTime.back());

        int maxTime = 0;
        int sum = 0;
        for(int i = 0; i<k+1; i++){
            sum += gap[i];
        }
        maxTime = max(maxTime,sum);
        int l = 0;
        int r = k;
        while(r<gap.size()-1){
            sum -= gap[l++];
            sum += gap[++r];
            maxTime = max(sum,maxTime);
        }
        return maxTime;
    }
};