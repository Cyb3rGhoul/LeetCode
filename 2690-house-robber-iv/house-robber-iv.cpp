class Solution {
public:
    bool canRob(vector<int>& nums, int k, int cap) {
        int count = 0;
        int i = 0;
        
        while (i < nums.size()) {
            if (nums[i] <= cap) { // Agar ghar ka paisa cap se kam hai to loot lo
                count++;
                i++; // Agle wale ghar ko skip karna hai (adjacent nahi lootsakte)
            }
            i++; // Agle ghar pe move karna hai
        }
        
        return count >= k; // Kya hum kam se kam 'k' ghar loot paaye?
    }
    
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (canRob(nums, k, mid)) {
                right = mid; // Try karte hai chhoti capability se
            } else {
                left = mid + 1; // Capability badhane ki zaroorat hai
            }
        }
        
        return left; // Minimum possible capability
    }
};