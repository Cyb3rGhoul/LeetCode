class FindSumPairs {
public:
    vector<int> arr1, arr2;
    unordered_map<int, int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // khoi tao va dem freq trong arr2
        arr1 = nums1;
        arr2 = nums2;
        for(auto& a2 : arr2){
            freq[a2]++;
        }
    }
    
    void add(int index, int val) {
        // giam, tang freq cua arr2[index] cu va moi
        freq[arr2[index]]--;
        arr2[index] += val;
        freq[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto& a1 : arr1){
            // voi moi a1, map no voi tat ca a2 -> cong vao ans
            int a2 = tot - a1;
            if(freq.count(a2)){
                ans += freq[a2];
            }
        }
        return ans;
    }
};