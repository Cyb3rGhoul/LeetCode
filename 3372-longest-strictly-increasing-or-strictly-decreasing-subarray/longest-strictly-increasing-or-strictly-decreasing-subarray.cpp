class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0; // Fix: If empty array, return 0.

    int l = 0, r = 0, res = 1;
    int inc = 0; // 0: unset, 1: increasing, -1: decreasing

    while (r < n - 1) {
        if (nums[r] < nums[r + 1]) { // Increasing sequence
            if (inc == -1) { 
                l = r; // Fix: Reset `l` only if switching from decreasing
            }
            inc = 1;
        } 
        else if (nums[r] > nums[r + 1]) { // Decreasing sequence
            if (inc == 1) {
                l = r; // Fix: Reset `l` only if switching from increasing
            }
            inc = -1;
        } 
        else { // Equal elements break monotonicity
            l = r + 1;
            inc = 0; // Reset trend
        }

        r++;
        res = max(res, r - l + 1);
    }

    return res;
}

};