class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<n && nums[l]==temp[l]){
            l++;
        }
        if(l==n) return 0;
        while(r>=0 && nums[r] == temp[r]){
            r--;
        }

        return n-(l+(n-r))+1;
        
    }
};