class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i == n || j == m) {
            return INT_MIN;
        }

        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int take = nums1[i] * nums2[j];

        int next = solve(i + 1, j + 1, nums1, nums2);
        if (next != INT_MIN) {
            take = max(take, take + next);
        }

        int skip1 = solve(i + 1, j, nums1, nums2);
        int skip2 = solve(i, j + 1, nums1, nums2);

        return dp[i][j] = max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        dp.assign(n, vector<int>(m, INT_MIN));

        return solve(0, 0, nums1, nums2);
    }
};
