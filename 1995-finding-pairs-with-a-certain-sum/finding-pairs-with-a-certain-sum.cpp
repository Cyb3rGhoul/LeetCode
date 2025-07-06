class FindSumPairs {
private:
    unordered_map<int, int> nums1_freq;  // Frequency map for nums1
    vector<int> nums2;                   // Copy of nums2 for modifications
    unordered_map<int, int> nums2_freq;  // Frequency map for current nums2 state
    
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2_input) {
        // Build frequency map for nums1
        nums1_freq.reserve(nums1.size());
        for(int num : nums1) {
            nums1_freq[num]++;
        }
        
        // Copy nums2 and build its frequency map
        nums2 = nums2_input;
        nums2_freq.reserve(nums2.size());
        for(int num : nums2) {
            nums2_freq[num]++;
        }
    }
    
    void add(int index, int val) {
        // Update frequency map: remove old value, add new value
        int old_val = nums2[index];
        int new_val = old_val + val;
        
        // Update frequency map
        nums2_freq[old_val]--;
        if(nums2_freq[old_val] == 0) {
            nums2_freq.erase(old_val);
        }
        nums2_freq[new_val]++;
        
        // Update the actual array
        nums2[index] = new_val;
    }
    
    int count(int tot) {
        int result = 0;
        
        // Iterate through nums2 frequency map instead of the array
        for(const auto& [num2, freq2] : nums2_freq) {
            int complement = tot - num2;
            auto it = nums1_freq.find(complement);
            if(it != nums1_freq.end()) {
                result += it->second * freq2;
            }
        }
        
        return result;
    }
};