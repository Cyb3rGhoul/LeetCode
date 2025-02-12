class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double curr = 0;
        for(int i = 0; i<k; i++){
            curr += (double)nums[i];
        }

        double avg = curr/k;

        for(int i = k; i<n; i++){
            curr += nums[i] - nums[i-k];
            avg = max(avg, curr/k);
        }

        return avg;
    }
};