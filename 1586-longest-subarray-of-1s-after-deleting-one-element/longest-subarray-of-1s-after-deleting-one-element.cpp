class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = 0, maxLen = 0, zeroCount = 0;

    while (r < n) {
        if (nums[r] == 0) zeroCount++;

        while (zeroCount > 1) {  // More than one zero, shift left pointer
            if (nums[l] == 0) zeroCount--;
            l++;
        }

        maxLen = max(maxLen, r - l); // r - l gives the size after deleting one zero
        r++;
    }

    return maxLen;
}

};