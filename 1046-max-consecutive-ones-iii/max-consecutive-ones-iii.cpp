class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int l = 0, r = 0, zctn = 0, maxLen = 0;

    while (r < nums.size()) {
        if (nums[r] == 0) zctn++; // Increment zero count if zero is found

        while (zctn > k) { // Shrink window if zero count exceeds k
            if (nums[l] == 0) zctn--; 
            l++; // Move left pointer
        }

        maxLen = max(maxLen, r - l + 1); // Update max length
        r++; // Expand window
    }

    return maxLen;
}

};