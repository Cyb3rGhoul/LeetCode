class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    int maxSum = 0, minSum = 0, sum = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        res = max(res, abs(sum - minSum));
        res = max(res, abs(sum - maxSum));

        maxSum = max(maxSum, sum);
        minSum = min(minSum, sum);
    }

    return res;
}

};